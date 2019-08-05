#include "PSM/api.hpp"

extern "C" void QuantileRegression_api
(	int *n,	/*row num*/
	int *d,	/*col num*/
	double *_X,
	double *_y,
	int max_it,
	double lambda_threshold,
	int *T,
	double *lambda_list,
	double *x_list,
	double *y_list
 ){
	MatrixXd XX(n, d);
	VectorXd yy(n);
	VectorXd x;
	for(int row = 0; row < n; ++row){
		for(int col = 0; col < d; ++col){
			XX(row, col) = X[row * d + col];
		}
		yy(row) = y[row];
	}
	PLP *p = QuantileRegression(X, y);
	PSM psm(p);
	PSMresult result = psm.solve(max_it, lambda_threshold);
	x.resize(result.d);
	for(int t = 0; t < T; ++t){
		lambda_list[t] = result.lambda_list[t];
		x = result.x_list.col(t);
		for(int i = 0; i < d; ++i){
			x_list[t*d+i] = x[i] - x[i+d];
		}
		y_list[t] = result.y_list[t];
	}
}

extern "C" void SparseSVM_api
(	int *n,	/*row num*/
	int *d,	/*col num*/
	double *_X,
	double *_y,
	int max_it,
	double lambda_threshold,
	int *T,
	double *lambda_list,
	double *x_list,
	double *y_list,
	double *x0
 ){
	MatrixXd XX(n, d);
	VectorXd yy(n);
	VectorXd x;
	for(int row = 0; row < n; ++row){
		for(int col = 0; col < d; ++col){
			XX(row, col) = X[row * d + col];
		}
		yy(row) = y[row];
	}
	PLP *p = SparseSVM(X, y);
	PSM psm(p);
	PSMresult result = psm.solve(max_it, lambda_threshold);
	x.resize(result.d);
	for(int t = 0; t < T; ++t){
		lambda_list[t] = result.lambda_list[t];
		x = result.x_list.col(t);
		for(int i = 0; i < d; ++i){
			x_list[t*d+i] = x[2*n+i] - x[2*n+d+i];
		}
		y_list[t] = result.y_list[t];
		x0[t] = x[2*n+2*d] - x[2*n+2*d+1];
	}
}

extern "C" void Dantzig_api
(	int *n,	/*row num*/
 int *d,	/*col num*/
 double *_X,
 double *_y,
 int max_it,
 double lambda_threshold,
 int *T,
 double *lambda_list,
 double *x_list,
 double *y_list
 ){
	MatrixXd XX(n, d);
	VectorXd yy(n);
	VectorXd x;
	for(int row = 0; row < n; ++row){
		for(int col = 0; col < d; ++col){
			XX(row, col) = X[row * d + col];
		}
		yy(row) = y[row];
	}
	PLP *p = Dantzig(X, y);
	PSM psm(p);
	PSMresult result = psm.solve(max_it, lambda_threshold);
	x.resize(result.d);
	for(int t = 0; t < T; ++t){
		lambda_list[t] = result.lambda_list[t];
		x = result.x_list.col(t);
		for(int i = 0; i < d; ++i){
			x_list[t*d+i] = x[i] - x[i+d];
		}
		y_list[t] = result.y_list[t];
	}
}

extern "C" void CompressedSensing_api
(	int *n,	/*row num*/
 int *d,	/*col num*/
 double *_X,
 double *_y,
 int max_it,
 double lambda_threshold,
 int *T,
 double *lambda_list,
 double *x_list,
 double *y_list
 ){
	MatrixXd XX(n, d);
	VectorXd yy(n);
	VectorXd x;
	for(int row = 0; row < n; ++row){
		for(int col = 0; col < d; ++col){
			XX(row, col) = X[row * d + col];
		}
		yy(row) = y[row];
	}
	PLP *p = CompressedSensing(X, y);
	PSM psm(p);
	PSMresult result = psm.solve(max_it, lambda_threshold);
	x.resize(result.d);
	for(int t = 0; t < T; ++t){
		lambda_list[t] = result.lambda_list[t];
		x = result.x_list.col(t);
		for(int i = 0; i < d; ++i){
			x_list[t*d+i] = x[i] - x[i+d];
		}
		y_list[t] = result.y_list[t];
	}
}
