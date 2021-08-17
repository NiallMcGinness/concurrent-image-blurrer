#!/bin/bash

mkdir -p input

wget https://appctl-test-images-public.s3.us-west-2.amazonaws.com/img/test_data_128_items.tar.gz

tar -xf test_data_128_items.tar.gz -C input/