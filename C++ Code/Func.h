#pragma once

#include <iostream>
#include <string>
#include <Eigen/Dense>
#include <Eigen/LU>
#include <vector>
#include <fstream>
#include <cmath>
#include <random>
#include <algorithm>

using namespace Eigen;
using namespace std;

extern double coef0;
extern double coef1;
extern double coef2;
extern double coef3;
extern double numCon;
extern double gdc0, gdc1, gdc2, gdc3, gdcNumCon; //Placeholders that store trained regression parameters
extern double gdError;

MatrixXd openData(string fileToOpen);

MatrixXd matrixShuffle(MatrixXd matrix);

tuple<MatrixXd, MatrixXd, MatrixXd, MatrixXd> trainTestSplit(MatrixXd matrix, float train_size);

float OLS_func(MatrixXd X, MatrixXd y, MatrixXd theta);

tuple<VectorXd, vector<float>> GradDescent(MatrixXd X, MatrixXd y, VectorXd theta, float alpha, int iters);

VectorXd Mean(Eigen::MatrixXd data);


VectorXd Std(Eigen::MatrixXd data);

MatrixXd Normalize(Eigen::MatrixXd data);

double FtoC(double num);

double CtoF(double num);

double feetToMeters(double num);

double RSquared(MatrixXd y, MatrixXd y_hat);

double meanAbsoluteError(MatrixXd y_test, MatrixXd X_test, double c0, double c1, double c2, double c3, double numConstant, bool flag);