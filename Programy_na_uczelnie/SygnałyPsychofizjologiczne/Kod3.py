features_2 = ['sqft_living', 'bedrooms']

X_train_2 = houses_train[features_2]
X_test_2  = houses_test[features_2]
y_train   = houses_train['price']
y_test    = houses_test['price']

regr_2 = linear_model.LinearRegression()
regr_2.fit(X_train_2, y_train)

pred_2 = regr_2.predict(X_test_2)
mse_2  = metrics.mean_squared_error(y_test, pred_2)
rmse_2 = np.sqrt(mse_2)

print("TASK 3 — Two-variable model (sqft_living + bedrooms)")
print("=" * 45)
for feat, coef in zip(features_2, regr_2.coef_):
    print(f"  θ ({feat:<15}): {coef:>12.4f}")
print(f"  θ0 (intercept)     : {regr_2.intercept_:>12.4f}")
print(f"\n  RMSE: ${rmse_2:,.0f}")
print(f"\n  vs sqft_living only RMSE: ${rmse_sqft:,.0f}")
improvement = (1 - rmse_2 / rmse_sqft) * 100
print(f"  Improvement: {improvement:+.2f}%")