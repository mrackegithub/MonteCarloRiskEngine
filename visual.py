import matplotlib.pyplot as plt

# -------------------------------------------------------------------------
# Step 1: Read the numbers from the C output file
# -------------------------------------------------------------------------
# 'output.txt' contains 200,000 numbers separated by spaces.
# We open the file, read the full string, and use .split() to break it up 
# by whitespace (spaces, tabs, newlines) into a list of word strings.
print("Reading output.txt...")
with open("output.txt", "r") as file:
    text_data = file.read().split()

# Convert each string into a floating-point number (equivalent to double in C)
values = [float(num) for num in text_data]
print(f"Loaded {len(values)} numbers successfully.")

# -------------------------------------------------------------------------
# Step 2: Calculate symmetric boundaries around 0
# -------------------------------------------------------------------------
# To center 0 on the graph, the left edge (-limit) and the right edge (+limit)
# must be the exact same distance from 0.
# We find the furthest point from zero in either direction using abs().
min_val = min(values)
max_val = max(values)
limit = max(abs(min_val), abs(max_val))

print(f"Data range: [{min_val:.3f}, {max_val:.3f}]")
print(f"Symmetric plot boundary: [-{limit:.3f}, +{limit:.3f}]")

# -------------------------------------------------------------------------
# Step 3: Create the histogram plot
# -------------------------------------------------------------------------
# Create a figure window of size 10 inches wide by 6 inches tall
plt.figure(figsize=(10, 6))

# plt.hist() groups the numbers into buckets ("bins") and counts how many 
# numbers fall into each bucket:
# - bins=100: Divide the total span into 100 equal-width columns.
# - range=(-limit, limit): Forces the 100 bins to be evenly and symmetrically 
#   distributed between -limit and +limit. Because the range is symmetric,
#   bin boundaries line up symmetrically around 0.
# - color="skyblue", edgecolor="black": Colors the bars and adds outlines.
plt.hist(values, bins=100, range=(-limit, limit), color="skyblue", edgecolor="black")

# -------------------------------------------------------------------------
# Step 4: Visual centering around 0
# -------------------------------------------------------------------------
# 1. Force the horizontal (X) axis to show exactly from -limit to +limit.
#    This guarantees that 0 is positioned dead center horizontally.
plt.xlim(-limit, limit)

# 2. Draw a prominent vertical dashed line at X = 0 to mark the center.
plt.axvline(0, color="red", linestyle="--", linewidth=2, label="Center (0)")

# -------------------------------------------------------------------------
# Step 5: Labels, Grid, and Display
# -------------------------------------------------------------------------
plt.title("Monte Carlo Risk Engine - Standard Normal Distribution", fontsize=14)
plt.xlabel("Value (Z-score)", fontsize=12)
plt.ylabel("Count / Frequency", fontsize=12)
plt.grid(axis="y", alpha=0.3)  # Subtle horizontal grid lines for readability
plt.legend()                   # Shows the legend for the red center line

# Show the interactive plot window
plt.show()

