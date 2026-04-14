# ── 1. Train/Test Split ───────────────────────────────────────────────────────
houses_train, houses_test = model_selection.train_test_split(
    houses, test_size=0.33, random_state=42
)

print(f"Training set size: {len(houses_train)}")
print(f"Test set size:     {len(houses_test)}")

# ── 2 & 3. Model: bathrooms ───────────────────────────────────────────────────
regr_bathrooms = linear_model.LinearRegression()
regr_bathrooms.fit(houses_train['bathrooms'].values.reshape(-1, 1),
                   houses_train['price'])

theta_1_b = regr_bathrooms.coef_[0]
theta_0_b = regr_bathrooms.intercept_

bf = bokeh.plotting.figure(width=1000, height=400, title="Model for: bathrooms")
bf.scatter(houses_train['bathrooms'], houses_train['price'], alpha=0.3)
x = np.linspace(0, max(houses_train['bathrooms']), 100)
bf.line(x, theta_1_b * x + theta_0_b, legend_label="Regression", color='green', line_width=2)
bokeh.plotting.show(bf)

# Predict & evaluate – bathrooms
pred_bathrooms = regr_bathrooms.predict(houses_test['bathrooms'].values.reshape(-1, 1))
mse_bathrooms  = metrics.mean_squared_error(houses_test['price'], pred_bathrooms)
rmse_bathrooms = np.sqrt(mse_bathrooms)

# ── 2 & 3. Model: sqft_living ─────────────────────────────────────────────────
regr_sqft = linear_model.LinearRegression()
regr_sqft.fit(houses_train['sqft_living'].values.reshape(-1, 1),
              houses_train['price'])

theta_1_s = regr_sqft.coef_[0]
theta_0_s = regr_sqft.intercept_

sf = bokeh.plotting.figure(width=1000, height=400, title="Model for: sqft_living")
sf.scatter(houses_train['sqft_living'], houses_train['price'], alpha=0.3)
x = np.linspace(0, max(houses_train['sqft_living']), 100)
sf.line(x, theta_1_s * x + theta_0_s, legend_label="Regression", color='orange', line_width=2)
bokeh.plotting.show(sf)

# Predict & evaluate – sqft_living
pred_sqft  = regr_sqft.predict(houses_test['sqft_living'].values.reshape(-1, 1))
mse_sqft   = metrics.mean_squared_error(houses_test['price'], pred_sqft)
rmse_sqft  = np.sqrt(mse_sqft)

# ── 4 & 5. Compare performance ────────────────────────────────────────────────
print("=" * 45)
print(f"{'Model':<15} {'MSE':>20} {'RMSE':>10}")
print("=" * 45)
print(f"{'bathrooms':<15} {mse_bathrooms:>20.0f} {rmse_bathrooms:>10.0f}")
print(f"{'sqft_living':<15} {mse_sqft:>20.0f} {rmse_sqft:>10.0f}")
print("=" * 45)

improvement = (1 - rmse_sqft / rmse_bathrooms) * 100
print(f"\nsqft_living model is ~{improvement:.1f}% better (lower RMSE)")