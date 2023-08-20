-- phpMyAdmin SQL Dump
-- version 5.1.1
-- https://www.phpmyadmin.net/
--
-- Host: 127.0.0.1
-- Generation Time: Jun 08, 2022 at 08:14 AM
-- Server version: 10.4.22-MariaDB
-- PHP Version: 8.0.13

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `sql_employee_database`
--

-- --------------------------------------------------------

--
-- Table structure for table `department`
--

CREATE TABLE `department` (
  `dep_id` int(11) NOT NULL,
  `dep_name` varchar(50) DEFAULT NULL,
  `dep_location` varchar(50) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `department`
--

INSERT INTO `department` (`dep_id`, `dep_name`, `dep_location`) VALUES
(1001, 'FINANCE', 'SYDNEY'),
(2001, 'AUDIT', 'MELBOURNE'),
(3001, 'MARKETING', 'PERTH'),
(4001, 'PRODUCTION', 'BRISBANE');

-- --------------------------------------------------------

--
-- Table structure for table `employees`
--

CREATE TABLE `employees` (
  `emp_id` int(11) NOT NULL,
  `emp_name` varchar(100) DEFAULT NULL,
  `job_name` varchar(100) DEFAULT NULL,
  `manager_id` int(11) DEFAULT NULL,
  `hire_date` date DEFAULT NULL,
  `salary` decimal(10,2) DEFAULT NULL,
  `commission` decimal(10,2) DEFAULT NULL,
  `dep_id` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `employees`
--

INSERT INTO `employees` (`emp_id`, `emp_name`, `job_name`, `manager_id`, `hire_date`, `salary`, `commission`, `dep_id`) VALUES
(63679, 'SANDRINE', 'CLERK', 69062, '1990-12-18', '900.00', NULL, 2001),
(64989, 'ADELYN', 'SALESMAN', 66928, '1991-02-20', '1700.00', '400.00', 3001),
(65271, 'WADE', 'SALESMAN', 66928, '1991-02-22', '1350.00', '600.00', 3001),
(65646, 'JONAS    ', 'MANAGER', 68319, '1991-04-02', '2957.00', NULL, 2001),
(66564, 'MADDEN', 'SALESMAN', 66928, '1991-09-28', '1350.00', '1500.00', 3001),
(66928, 'BLAZE    ', 'MANAGER   ', 68319, '1991-05-01', '2750.00', NULL, 3001),
(67832, 'CLARE    ', 'MANAGER   ', 68319, '1991-06-09', '2550.00', NULL, 1001),
(67858, 'SCARLET', 'ANALYST', 65646, '1997-04-19', '3100.00', NULL, 2001),
(68319, 'KAYLING  ', 'PRESIDENT ', NULL, '1991-11-18', '6000.00', NULL, 1001),
(68454, 'TUCKER', 'SALESMAN', 66928, '1991-09-08', '1600.00', '0.00', 3001),
(68736, 'ADNRES', 'CLERK', 67858, '1997-05-23', '1200.00', NULL, 2001),
(69000, 'JULIUS', 'CLERK', 66928, '1991-12-03', '1050.00', NULL, 3001),
(69062, 'FRANK', 'ANALYST', 65646, '1991-12-03', '3100.00', NULL, 2001),
(69324, 'MARKER', 'CLERK', 67832, '1992-01-23', '1400.00', NULL, 1001);

-- --------------------------------------------------------

--
-- Table structure for table `salary_grade`
--

CREATE TABLE `salary_grade` (
  `grade` int(11) NOT NULL,
  `min_sal` int(11) NOT NULL,
  `max_sal` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `salary_grade`
--

INSERT INTO `salary_grade` (`grade`, `min_sal`, `max_sal`) VALUES
(1, 800, 1300),
(2, 1301, 1500),
(3, 1501, 2100),
(4, 2101, 3100),
(5, 3101, 9999);

--
-- Indexes for dumped tables
--

--
-- Indexes for table `employees`
--
ALTER TABLE `employees`
  ADD PRIMARY KEY (`emp_id`);
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
