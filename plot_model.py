import sys
import matplotlib.pyplot as plt
import numpy as np
import csv

def load_model(model_path):
    with open(model_path, 'r') as f:
        bias, weight, minX, maxX = map(float, f.read().split())
    return bias, weight, minX, maxX

def load_csv_data(csv_path):
    data = []
    with open(csv_path, 'r') as f:
        reader = csv.reader(f)
        next(reader)  # Skip header
        for row in reader:
            if len(row) >= 2:
                try:
                    x, y = float(row[0]), float(row[1])
                    data.append((x, y))
                except ValueError:
                    continue
    return data

def normalize(x, minX, maxX):
    return 2.0 * (x - minX) / (maxX - minX) - 1.0

def estimate_y(x, bias, weight, minX, maxX):
    return bias + weight * normalize(x, minX, maxX)

def plot(bias, weight, minX, maxX, data):
    x_vals = np.linspace(minX, maxX, 100)
    y_vals = [estimate_y(x, bias, weight, minX, maxX) for x in x_vals]

    plt.figure(figsize=(8, 6))
    plt.plot(x_vals, y_vals, label="Regression Line", color="blue")
    
    if data:
        xs, ys = zip(*data)
        plt.scatter(xs, ys, label="Original Data", color="red")

    plt.xlabel("x")
    plt.ylabel("y")
    plt.title("Linear Regression: Data + Prediction Line")
    plt.legend()
    plt.grid(True)

    try:
        plt.show()
    except:
        print("⚠️ GUI not available")

def compute_mae(data, bias, weight, minX, maxX):
    """
    Calcule l'erreur moyenne absolue (MAE) sur l'ensemble des points.
    """
    errors = []
    for x, y in data:
        y_pred = estimate_y(x, bias, weight, minX, maxX)
        errors.append(abs(y_pred - y))
    if not errors:
        return None
    return sum(errors) / len(errors)

if __name__ == "__main__":
    if len(sys.argv) != 3:
        print("Usage: python3 plot_model.py data.csv model.mo")
        sys.exit(1)
    
    data_file = sys.argv[1]
    model_file = sys.argv[2]

    data = load_csv_data(data_file)
    bias, weight, minX, maxX = load_model(model_file)

    mae = compute_mae(data, bias, weight, minX, maxX)
    if mae is not None:
        print(f"📊 Erreur moyenne absolue (MAE) : {mae:.4f}")
    else:
        print("⚠️ Aucune donnée pour calculer la MAE.")

    plot(bias, weight, minX, maxX, data)