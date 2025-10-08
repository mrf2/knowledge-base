# Microservices and Monoliths
One of the biggest use cases and strongest drivers behind the uptake of containers are ***microservices***.

**Microservices** are a way of developing and composing software systems such that they are built out of small, independent components that interact with one another over the network. This is contrast to the traditional ***monolithics*** way of developing software, where there is a single large program, typically written in C++ or Java.

When it comes to scaling a monolith, commonly the only choice is to scale up, where extra demand is handled by using a larger machine with more RAM and CPU power. Converrsely, microservices are degined to ***scale out***, where extra demand is handled by provisioning multiple machines the load can be spread over. In a microservice architecture, it's possible to only scale the resources required for a particular service, focusing on the bottlenecks in the system. In a monolith, it's scale everything or nothing, resulting in wasted resources.

In terms of complexity, microservices are a double-edge sword. Each individual microservice should be easy to understand and modify. However, in a system composed of dozens or hundreds of such services, the overall complexity increases due to the interaction between individual components.

The lightweight nature and speed of containers mean they are particularly well suited for running a microservice architecture. Compared to VMs, containers are vastly smaller and quicker to deploy, allowing microservice architectures to use the minimum of resources and react quickly to changes in demand.
