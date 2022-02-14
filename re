import boto3
import re
import pandas as pd
session = boto3.Session(profile_name = 'default') #s3 = session.client('s3', region_name='us-east-1')
s3_resource = session.resource('s3')

myBucket = s3_resource.Bucket('vlinkucket1')

bucket_objects = myBucket.objects.all()

for each_object in bucket_objects:
    match = r'\w+'
    if re.search(match,  each_object.key):  
        print(each_object.key)
        
mydata = []
for each_bucket in myBucket.objects.all():
    mydata.append([each_bucket.bucket_name, each_bucket.key, each_bucket.storage_class])

df = pd.DataFrame(mydata, columns = ['Bucket Name', 'File', 'Storage Class'])
df.to_csv('s3_inventory.csv', index=False)
