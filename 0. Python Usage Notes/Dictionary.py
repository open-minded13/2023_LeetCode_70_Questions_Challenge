# Create an empty dictionary
my_dict = {}


# Add/Update key-value pairs to the dictionary
my_dict["apple"] = 3
my_dict["banana"] = 4
my_dict["orange"] = 5

# Another way to add and update values:
my_dict = {"apple": 8, "banana": 8, "candy": 8}


# Access values using keys
print("apple is:", my_dict["apple"])

# Use the get() method to access a value with a fallback
print("guava is:", my_dict.get("guava", 0))  # If 'guava' key doesn't exist, return 0

# Check if a key exists in the dictionary
if "banana" in my_dict:
    print("banana is in my_dict")
else:
    print("banan is not in my_dict")


# Iterate over the keys and values in the dictionary
# In Python, the my_dict.items() method returns a view object that
# contains the key-value pairs of the dictionary my_dict.
# This view object can be used to iterate over the keys and values of the dictionary.
for key, value in my_dict.items():
    print(key, ":", value)

# Get a list of keys
keys = list(my_dict.keys())
print("keys:", keys)

# Get a list of values
values = list(my_dict.values())
print("values:", values)


# Remove key-value pairs:
del my_dict["banana"]
if "banana" not in my_dict:
    print("banana is not in my_dict")

# Remove a key-value pair using pop()
apple_count = my_dict.pop("apple")  # apple's value pop and store into apple_count.
print("apple_count:", apple_count)
if "apple" not in my_dict:
    print("apple is not in my_dict")
