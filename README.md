# concurrent-image-blurrer

This program reads jpeg or png files from an input directory, blurs the image with an OpenCV function and saves the result to an output directory.

It is multithreaded and accepts 2 flags 

 --threads for the number of threads to run 
 --cycles for the number of times to run over the input directory

example use 

```bash

./bin.app --threads=3 --cycles=2

```

The purpose of this is mainly to use as an example program to run ebpf tracing tools on


