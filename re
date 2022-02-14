import boto3
import re
session = boto3.Session(profile_name = 'default')
s3_resource = session.resource('s3')

myBucket = s3_resource.Bucket('vlinkucket1')

bucket_objects = myBucket.objects.all()

for each_objects in bucket_objects:
    match = r'\w+'
    if re.search(match,  each_objects.key):  
        print(each_objects.key)
