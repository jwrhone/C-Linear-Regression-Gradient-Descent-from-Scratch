#include "Func.h"

#include <iostream>
#include <string>
#include <Eigen/Dense>
#include <Eigen/LU>
#include <vector>
#include <fstream>
#include <cmath>
#include <random>
#include <algorithm>

using Eigen::MatrixXd;
using namespace std;

double coef0;
double coef1;
double coef2;
double coef3;
double numCon;
double gdc0, gdc1, gdc2, gdc3, gdcNumCon; //Placeholders that store trained regression parameters
double gdError;

MatrixXd openData(string fileToOpen)
{

	vector<double> matrixEntries;

	// in this object we store the data from the matrix
	ifstream matrixDataFile;
	matrixDataFile.open(fileToOpen);

	if (matrixDataFile.is_open()) {
		cout << "Loaded CSV" << endl;
	}
	else {
		cout << "NO CSV";
	}

	// this variable is used to store the row of the matrix that contains commas 
	string matrixRowString;

	// this variable is used to store the matrix entry;
	string matrixEntry;

	// this variable is used to track the number of rows
	int matrixRowNumber = 0;


	while (getline(matrixDataFile, matrixRowString)) // here we read a row by row of matrixDataFile and store every line into the string variable matrixRowString
	{
		stringstream matrixRowStringStream(matrixRowString); //convert matrixRowString that is a string to a stream variable.

		while (getline(matrixRowStringStream, matrixEntry, ',')) // here we read pieces of the stream matrixRowStringStream until every comma, and store the resulting character into the matrixEntry
		{
			matrixEntries.push_back(stod(matrixEntry));   //here we convert the string to double and fill in the row vector storing all the matrix entries
		}
		matrixRowNumber++; //update the column numbers
	}

	// here we convet the vector variable into the matrix and return the resulting object, 
	// note that matrixEntries.data() is the pointer to the first memory location at which the entries of the vector matrixEntries are stored;
	return Map<Matrix<double, Dynamic, Dynamic, RowMajor>>(matrixEntries.data(), matrixRowNumber, matrixEntries.size() / matrixRowNumber);

}

MatrixXd matrixShuffle(MatrixXd matrix) {
	random_device r;
	seed_seq rng_seed{r(), r(), r(), r(), r(), r(), r(), r()};

	mt19937 eng1(rng_seed);

	PermutationMatrix<Dynamic, Dynamic> permX(matrix.rows());
	permX.setIdentity();
	shuffle(permX.indices().data(), permX.indices().data() + permX.indices().size(), eng1);
	MatrixXd shuffle_matrix = permX * matrix;
	return shuffle_matrix;
}

double meanAbsoluteError(MatrixXd y_test, MatrixXd X_test, double c0, double c1, double c2, double c3, double numConstant, bool flag) {
	MatrixXd y_hat(y_test.rows(), y_test.cols());
	double min_temp, current_temp, month, elevation;
	
	if (flag == true) {
		for (int i = 0; i < y_hat.rows(); i++) {
			min_temp = X_test(i, 0);
			current_temp = X_test(i, 1);
			month = X_test(i, 2);
			elevation = X_test(i, 3);

			y_hat(i, 0) = (min_temp * c0) + (current_temp * c1) + (month * c3) + (elevation * c3) + numConstant;
		}
	}
	if (flag == false) {
		for (int i = 0; i < y_hat.rows(); i++) {
			min_temp = X_test(i, 0);
			current_temp = X_test(i, 1);
			month = X_test(i, 2);

			y_hat(i, 0) = (min_temp * c0) + (current_temp * c1) + (month * c3) + numConstant;
		}
	}

	double sum_err = 0;
	for (int j = 0; j < y_test.rows(); j++) {
		sum_err += abs(y_hat(j, 0) - y_test(j, 0));
	}
	return sum_err / double(y_test.rows()); 
}
tuple<MatrixXd, MatrixXd, MatrixXd, MatrixXd> trainTestSplit(MatrixXd matrix, float train_size) {
	int rows = matrix.rows();
	int train_rows = round(train_size * rows);
	int test_rows = rows - train_rows;

	MatrixXd train = matrix.topRows(train_rows);

	MatrixXd X_train = train.rightCols(matrix.cols() - 1);
	MatrixXd y_train = train.leftCols(1);

	MatrixXd test = matrix.bottomRows(test_rows);

	MatrixXd X_test = test.rightCols(matrix.cols() - 1);
	MatrixXd y_test = test.leftCols(1);

	return make_tuple(X_train, y_train, X_test, y_test);
}

float OLS_func(MatrixXd X, MatrixXd y, MatrixXd theta) {
	MatrixXd inner = pow(((X * theta) - y).array(), 2);
	return (inner.sum() / (2 * X.rows()));
}

tuple<VectorXd, vector<float>> GradDescent(MatrixXd X, MatrixXd y, VectorXd theta, float alpha, int iters) {

	MatrixXd tmp = theta; 
	int param = theta.rows(); //amount of variables dataset has
	vector<float> cost;
	cost.push_back(OLS_func(X, y, theta));//declaring initial cost that will be updated with calculated weights
	float lr = alpha;

	for (int i = 0; i < iters; ++i) {//Calculate error for each iteration to be multiplied to each feature
		MatrixXd error = X * theta - y; //Calculate iteration error
		for (int j = 0; j < param; ++j) {
			MatrixXd X_i = X.col(j); //Get jth features
			MatrixXd term = error.cwiseProduct(X_i); //Multiply all column features by error to get individual feature errors
			tmp(j, 0) = theta(j, 0) - ((lr / X.rows() * term.sum())); //Update theta, 
		}
		theta = tmp;
		cost.push_back(OLS_func(X, y, theta)); //Calculate new cost function values based on weigths
		if (lr > 0.001) {
			lr = lr / pow(iters, 0.25);
		}
	}

	return make_tuple(theta, cost);
}

VectorXd Mean(Eigen::MatrixXd data) {
	return data.colwise().mean();
}


VectorXd Std(Eigen::MatrixXd data) {
	return ((data.array().square().colwise().sum()) / (data.rows() - 1)).sqrt();
}

MatrixXd Normalize(Eigen::MatrixXd data) {

	VectorXd mean = Mean(data);
	Eigen::MatrixXd scaled_data = data.array().rowwise() - mean.transpose().array();

	VectorXd std = Std(scaled_data);

	Eigen::MatrixXd norm = scaled_data.array().rowwise() / std.transpose().array();

	return norm;
}

double RSquared(MatrixXd y, MatrixXd y_hat) {
	double num = pow((y - y_hat).array(), 2).sum();
	double den = pow(y.array() - y.mean(), 2).sum();
	return 1 - num / den;
}

double FtoC(double num) {
	return 5 * (num - 32) / 9;
}

double CtoF(double num) {
	return (9.0 / 5.0) * num + 32;
}

double feetToMeters(double num) {
	//The length in meters is equal to the feet multiplied by 0.3048.
	return num * 0.3048;
}