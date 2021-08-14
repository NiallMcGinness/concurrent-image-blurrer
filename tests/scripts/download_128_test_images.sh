#!/bin/bash

mkdir -p input

for i in {0..127}
do
wget 'https://appctl-test-images-public.s3.us-west-2.amazonaws.com/img/dataset_1-img-'$i'.png' -P input/
done