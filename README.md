# Study of Hardware-Software Co-design of Vehicle(Car) detection using HOG and SVM

RnD project done under Prof. Sachin Patkar as a part of a RnD course project (EE 692)

## Softwares Used

Vivado WebPACK 2019.1 

## Create HOG-SVM accelerator IP form HLS

Using the normal HLS synthesis flow create and export the IP 

## Create project using TCL


```tcl

source <path-to-build.tcl>/build.tcl

```

## Debugging any error encountered while sourcing build.tcl
	- ERROR: [BD_TCL-115] The following IPs are not found in the IP Catalog.
	Solution:
	- Change your IP repository path of HOG-SVM accelerator obtained from HLS in line no 153 of build.tcl




## Contributing
Pull requests are welcome. For major changes, please open an issue first to discuss what you would like to change.

Please make sure to update tests as appropriate.

## Some minor issues that I faced while uploading
[warning: LF will be replaced by CRLF and Special characters appear](https://github.com/gobuffalo/buffalo/issues/1189)

<!--## License
[MIT](https://choosealicense.com/licenses/mit/) -->