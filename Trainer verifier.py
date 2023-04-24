import cv2
import numpy as np
from tensorflow.keras.models import load_model

# Load the saved model
model = load_model(r"C:\Users\Asus\Desktop\Test2\road_classification_model.h5")

# Load and preprocess the new image
img_path = r"C:\Users\Asus\Desktop\UnPavedRoad__37.jpg"
img = cv2.imread(img_path)
print(img.shape)
img = cv2.resize(img, (150, 150))
img = np.expand_dims(img, axis=0)


# Use the model to predict the category of the new image
prediction = model.predict(img)

# Print the predicted category
if prediction[0][0] > 0.5:
    print("The road is unpaved.")
else:
    print("The road is smooth.")