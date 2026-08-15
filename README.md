# 🚗 Rental Vehicle Management System

## 1. Project Overview

The Rental Vehicle Management System is a C++ based application developed to simplify and organize the process of renting vehicles. The system allows users to view available vehicles, request a vehicle for rent, and manage their rental details. An admin can manage vehicles, check rental requests, and approve or reject them.

## 2. Problem Statement

Managing vehicle rentals manually can be time-consuming and may lead to problems such as duplicate bookings, incorrect records, and difficulty in tracking vehicle availability. This project provides a computerized solution to manage vehicles, customers, rental requests, and bookings in an organized and efficient way.

## 3. Objectives

* To simplify the vehicle rental process.
* To maintain vehicle and customer records efficiently.
* To display available vehicles to users.
* To manage rental requests through an admin.
* To prevent multiple users from booking the same vehicle.
* To demonstrate the use of Object-Oriented Programming concepts in C++.

## 4. Features

* User and Admin interfaces.
* Different vehicle categories such as Bike, Scooty, and Four-Wheeler.
* Display of available vehicles.
* Vehicle details including vehicle number and rent per day.
* Users can submit rental requests.
* Admin can view and manage rental requests.
* Admin can approve or reject requests.
* Vehicle allocation after approval.
* Vehicle availability is updated after allocation.

## 5. System Workflow

The basic working of the system is:

**User → View Vehicles → Select Vehicle → Submit Rental Request → Admin Reviews Request → Approve/Reject → Vehicle Allocated**

The admin manages the vehicle records and rental requests, while the user interacts with the system to select and request a vehicle.

## 6. OOP Concepts Used

The project is designed using important Object-Oriented Programming concepts:

* **Classes and Objects** – Used to represent vehicles, users, and rental-related information.
* **Encapsulation** – Used to keep data and related functions together.
* **Inheritance** – Used to create different types of vehicles from a common vehicle class.
* **Polymorphism** – Used to provide different behavior for different vehicle types.
* **Abstraction** – Used to hide unnecessary implementation details.
* **Constructors and Destructors** – Used for object initialization and cleanup.

## 7. Technologies Used

* **Programming Language:** C++
* **Concept:** Object-Oriented Programming
* **Compiler:** MinGW / GCC
* **Development Environment:** VS Code

## 8. Project Structure

The project is divided into different classes and components to make the code organized and easier to manage.

* **Vehicle Class** – Stores common vehicle details.
* **Bike Class** – Handles bike-specific information.
* **Scooty Class** – Handles scooty-specific information.
* **FourWheeler Class** – Handles four-wheeler information.
* **User Module** – Handles user operations and rental requests.
* **Admin Module** – Handles vehicle management and request approval.
* **Rental Module** – Handles rental and booking-related operations.

## 9. How to Run the Project

1. Clone the repository.
2. Open the project in VS Code or any C++ IDE.
3. Make sure a C++ compiler such as GCC/MinGW is installed.
4. Compile the source code.
5. Run the generated executable file.
6. Follow the instructions displayed in the terminal.

## 10. Screenshots / Demo









## 11. Sample Output

The application provides a menu-driven interface through which users can view vehicles, check their availability, and submit rental requests. The admin can then review these requests and approve or reject them based on vehicle availability.

## 12. Future Enhancements

The project can be further improved by adding:

* Database integration.
* Online payment system.
* Web-based or mobile interface.
* User authentication and profiles.
* Online booking and cancellation.
* Email/SMS notifications.
* Rental history and billing system.

## 13. Team Members

**Project Team:**

* Govind Rathi
* Harshada Patil
* Vaidehi Nakate

## 14. Acknowledgements

This project was developed as part of **Genesis 2K26** which was an intra-club competition for club members of Association of Computer Science and Engineering Student (ACSES) to demonstrate the practical implementation of Object-Oriented Programming concepts in C++.
We would like to thank our mentors for their guidance and support throughout the development of the project.
