# Offical Image Variants
Many of the official repositories for popular programming languages such as Python, Go, and Ruby contain multiple images for different purposes.

 * **slim**: These images are cut-down versions of the standard images. Many common packages and libraries will be missing. These are essential when we need to reduce on image size for distribution but often require extra work installing and maintaing packages already available in the standard image.

 * **onbuild**: These images use the Dockerfile ONBUILD instruction to delay execution of certain commands until a new "child" image is built that inherits the onbuild image. These commands are processed as part of the FROM instruction of the child image and typically do things like copy over code and run a compile step. These images can make it quicker and easier to get started with a language, but in the long-run, they tend to be limiting and confusing.
