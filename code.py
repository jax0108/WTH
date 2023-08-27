
#STEP 2 
"""
Collect images from Esp32-cam web server
"""
from logging import basicConfig, INFO
from everywhereml.data import ImageDataset
from everywhereml.data.collect import MjpegCollector

# you need to manually create this folder in the current working directory
base_folder = 'C:/Users/blazi/OneDrive/Desktop/WTH/feed'
# copy here the address printed on the Serial Monitor
# (the one after "MJPEG stream available at")
IP_ADDRESS_OF_ESP = 'http://192.168.43.41:81'
basicConfig(level=INFO)

image_dataset = ImageDataset.from_nested_folders(
        name='Dataset', 
        base_folder=base_folder
    ) 
# mjpeg_collector = MjpegCollector(address=IP_ADDRESS_OF_ESP)
# image_dataset = mjpeg_collector.collect_many_classes(
#     dataset_name='Dataset', 
#     base_folder=base_folder,        
#     duration=60
# )
  
print(image_dataset)

#STEP 3 
"""
Image classification with HOG works on grayscale images at the moment
So convert images to grayscale in the range 0-255
"""
image_dataset = image_dataset.gray().uint8()

"""
Preview grayscale images
"""
image_dataset.preview(
    samples_per_class=10, 
    rows_per_class=2, 
    figsize=(20, 10), 
    cmap='gray'
)
"""
Create an image recognition pipeline with HOG feature extractor
"""
from everywhereml.preprocessing.image.object_detection import HogPipeline
from everywhereml.preprocessing.image.transform import Resize

pipeline = HogPipeline(
    transforms=[
        Resize(width=40, height=30)
    ]
)

# Convert images to feature vectors
feature_dataset = pipeline.fit_transform(image_dataset)
feature_dataset.describe()

"""
Plot pairplot of features.
Feel free to open the image in a new window to see it at full scale.
In the next line:
 - n is the number of points to plot (the greater the value, the longer it takes)
 - k is the number of features (values greater than 10 become messy)
"""
feature_dataset.plot.features_pairplot(n=200, k=8)

"""
Plot UMAP of features
If features are discriminative, we should see well defined clusters of points
"""
feature_dataset.plot.umap()

"""
Create and fit RandomForest classifier
"""
from everywhereml.sklearn.ensemble import RandomForestClassifier

for i in range(10):
    clf = RandomForestClassifier(n_estimators=5, max_depth=10)

    # fit on train split and get accuracy on the test split
    train, test = feature_dataset.split(test_size=0.4, random_state=i)
    clf.fit(train)

  

# now fit on the whole dataset
clf.fit(feature_dataset)

"""
Export pipeline to C++
Replace the path to your actual sketch path
"""
print(pipeline.to_arduino_file(
    filename='C:/Users/blazi/OneDrive/Documents/Arduino/WTH/HogPipeline.h',
    instance_name='hog'
))

"""
Export classifier to C++
Replace the path to your actual sketch path

The class_map parameters convert numeric classes to human-readable strings
"""
print(clf.to_arduino_file(
    filename='C:/Users/blazi/OneDrive/Documents/Arduino/WTH/HogClassifier.h',
    instance_name='classifier', 
    class_map=feature_dataset.class_map
))