-- phpMyAdmin SQL Dump
-- version 5.1.1
-- https://www.phpmyadmin.net/
--
-- Host: 127.0.0.1
-- Generation Time: Jun 08, 2022 at 08:17 AM
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
-- Database: `sql_hr_database`
--

DELIMITER $$
--
-- Procedures
--
CREATE DEFINER=`root`@`localhost` PROCEDURE `errorHandling_SQLEXEC` ()  BEGIN
	DECLARE EXIT HANDLER FOR SQLEXCEPTION
	ROLLBACK ;
    SELECT 'An error occured operation rollbacked and stored procedure was terminated';
END$$

CREATE DEFINER=`root`@`localhost` PROCEDURE `getcountry` (IN `cityname` VARCHAR(20))  BEGIN
SELECT * from hr_locations where city=cityname;
END$$

CREATE DEFINER=`root`@`localhost` PROCEDURE `getCustomerCity` (IN `pCustId` INT, OUT `pCity` VARCHAR(50))  BEGIN
	DECLARE custCity varchar(100);
    SELECT city 
    INTO custCity 
    FROM customer 
    WHERE cust_id = pCustId ;
    
    CASE custCity
    	WHEN 'London' THEN
        	SET pCity = 'USA' ;
        WHEN 'Berlin' THEN
        	SET pCity = 'Spain';
        ELSE 
        	SET pCity = 'Japan';        	
    END CASE ;    
END$$

CREATE DEFINER=`root`@`localhost` PROCEDURE `getdepartmentname` (IN `dep_id` INT, OUT `total` INT)  BEGIN
SELECT COUNT(employee_id) INTO total from hr_employees where department_id=dep_id;
END$$

CREATE DEFINER=`root`@`localhost` PROCEDURE `getEmployees` ()  BEGIN
	SELECT * from hr_employees ;
END$$

CREATE DEFINER=`root`@`localhost` PROCEDURE `getOfficeByCountry_IN` (IN `pCountryName` VARCHAR(20))  BEGIN
    	SELECT * from hr_locations where country_Id  = pCountryName ; 
    END$$

CREATE DEFINER=`root`@`localhost` PROCEDURE `getSalaryByDepartment_IN_OUT` (IN `departmentName` VARCHAR(25), OUT `totalSalary` INT)  BEGIN
	SELECT SUM(Salary) INTO totalSalary
    FROM hr_employees
    WHERE job_id = departmentName ;
END$$

CREATE DEFINER=`root`@`localhost` PROCEDURE `getTotalSalary` ()  BEGIN
        	DECLARE totalSalary BIGINT DEFAULT 0;
            
        	SELECT SUM(Salary) 
            INTO totalSalary
            FROM hr_employees ;
            
            SELECT totalSalary ;
            
		END$$

CREATE DEFINER=`root`@`localhost` PROCEDURE `insertSupplierProduct` (IN `pSupplierId` INT, IN `pProductId` INT)  BEGIN
	DECLARE EXIT HANDLER FOR 1062
    BEGIN
    	SELECT CONCAT('Duplicate Key(',pSupplierId,',',pProductId,')Occured') AS Message ;
	END ;
    
    INSERT INTO supplierproducts(SupplierId,ProductId) VALUES (pSupplierId,pProductId);
    
    SELECT COUNT(*)  
    FROM supplierproducts
    WHERE SupplierId = pSupplierId;
END$$

CREATE DEFINER=`root`@`localhost` PROCEDURE `LeaveDemo` (OUT `result` VARCHAR(100))  BEGIN
	DECLARE counter INT DEFAULT 1;
    DECLARE times INT ;    
    SET times = ROUND(RAND()*(10-6)+6);
	SET result = '' ;
        
    label : LOOP    
    	SET result = concat(result,counter,',');        
        IF counter = times THEN
        	LEAVE label;
        END IF ;        
        SET counter = counter +1 ;    
    END LOOP ;    
END$$

CREATE DEFINER=`root`@`localhost` PROCEDURE `LoopDemo` ()  BEGIN
	DECLARE x INT DEFAULT 1;
    DECLARE str Varchar(50);
    
    SET str = '';
        label : LOOP

			IF x > 10 THEN
            	LEAVE label;
            END IF ;
			
            SET str = concat(str,x,',');
			SET x = x+1 ;
        END LOOP ;
        
        SELECT str ;
END$$

CREATE DEFINER=`root`@`localhost` PROCEDURE `proc_empList` ()  BEGIN 
	DECLARE v_empId INT ;
    DECLARE v_empName varchar(50);
    DECLARE v_empSalary BIGINT ;
    DECLARE v_finished INT DEFAULT 0;
    -- DECLARE CURSOR
    DECLARE c1 cursor FOR SELECT Employee_Id,First_Name,Salary from hr_employees ;
    DECLARE EXIT HANDLER FOR NOT FOUND SET v_finished = 1;
    OPEN c1 ;
    get_emp : LOOP
        FETCH c1 INTO v_empId,v_empName,v_empSalary ;
        IF v_finished = 1 THEN
        	LEAVE get_emp;
        END IF ;
        SELECT concat(v_empId,' ',v_empName,' ',v_empSalary) AS emp;
    END LOOP ;    
    CLOSE c1 ;
END$$

CREATE DEFINER=`root`@`localhost` PROCEDURE `proc_getCustomerLevel` (IN `pCustomerId` INT, OUT `pcustomerLevel` VARCHAR(20))  BEGIN

    DECLARE creditLimit INT DEFAULT 0 ;
    
    -- get credit limit of customer
    
    SELECT credit INTO creditLimit 
    FROM customer
    WHERE Cust_Id = pCustomerId ;
    
    -- Call function
    
    SET pcustomerLevel =  getCustomerLevel(creditLimit) ;

END$$

CREATE DEFINER=`root`@`localhost` PROCEDURE `RepeatDemo` ()  BEGIN
	DECLARE x INT DEFAULT 1;
    DECLARE str varchar(50) DEFAULT '' ;    
    REPEAT 
    	SET str =concat(str,x,',');
        SET  x = x + 1;
    UNTIL x >= 10 
    END REPEAT ;
    SELECT str ;
END$$

CREATE DEFINER=`root`@`localhost` PROCEDURE `SetCounter` (INOUT `counter` INT, IN `inc` INT)  BEGIN
    SET counter = counter + inc;
END$$

CREATE DEFINER=`root`@`localhost` PROCEDURE `setCustomerCity` (IN `customerId` INT, OUT `customerCity` VARCHAR(20))  BEGIN
	DECLARE customGrade INT DEFAULT 0 ;
    
    SELECT grade 
    INTO customGrade 
    FROM customer 
    WHERE cust_Id = customerId ;
    
    IF customGrade >= 300 THEN
    	SET customerCity = 'USA' ;
        -- SET customerId  = cust_Id ;
    END IF ;
    
END$$

CREATE DEFINER=`root`@`localhost` PROCEDURE `SetPurchaseAmount_inout_parameter` (INOUT `purchase_amt` INT, IN `inc` INT, IN `ord` INT)  BEGIN
    update orders SET purchase_amt = (purchase_amt + inc) where order_no=ord;
END$$

CREATE DEFINER=`root`@`localhost` PROCEDURE `WhileDemo` ()  BEGIN
	DECLARE x INT DEFAULT 1;
    DECLARE str varchar(50) DEFAULT '' ;
    
    WHILE x <= 10 DO
    	SET str = concat(str,x,',');
        SET x = x+1;
    END WHILE ;
    
    SELECT str ;
    
END$$

--
-- Functions
--
CREATE DEFINER=`root`@`localhost` FUNCTION `getCustomerLevel` (`credit` INT) RETURNS VARCHAR(50) CHARSET latin1 BEGIN 
	DECLARE customerLevel varchar(50) ;
    
    IF credit > 50000 THEN
    	SET customerLevel = 'PLATINUM';
    ELSEIF (credit >=10000 AND credit <=50000) THEN
    	SET customerLevel = 'GOLD';
    ELSEIF credit < 10000 THEN
    	SET customerLevel = 'SILVER' ;
    END IF ;
    RETURN (customerLevel) ;
END$$

CREATE DEFINER=`root`@`localhost` FUNCTION `getWorkingDays` (`startDate` DATE, `endDate` DATE) RETURNS INT(11) BEGIN
	RETURN DATEDIFF(endDate,startDate) ;
END$$

DELIMITER ;

-- --------------------------------------------------------

--
-- Table structure for table `hr_countries`
--

CREATE TABLE `hr_countries` (
  `country_id` varchar(20) NOT NULL,
  `country_name` varchar(40) NOT NULL,
  `region_id` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data for table `hr_countries`
--

INSERT INTO `hr_countries` (`country_id`, `country_name`, `region_id`) VALUES
('AR', 'Argentina', 2),
('AU', 'Australia', 3),
('BE', 'Belgium', 1),
('BR', 'Brazil', 2),
('CA', 'Canada', 2),
('CH', 'Switzerland', 1),
('CN', 'China', 3),
('DE', 'Germany', 1),
('DK', 'Denmark', 1),
('EG', 'Egypt', 4),
('FR', 'France', 1),
('IL', 'Israel', 4),
('IN', 'India', 3),
('IT', 'Italy', 1),
('JP', 'Japan', 3),
('KW', 'Kuwait', 4),
('ML', 'Malaysia', 3),
('MX', 'Mexico', 2),
('NG', 'Nigeria', 4),
('NL', 'Netherlands', 1),
('SG', 'Singapore', 3),
('UK', 'United Kingdom', 1),
('US', 'United States of America', 2),
('ZM', 'Zambia', 4),
('ZW', 'Zimbabwe', 4),
('MX', 'Mexico', 2),
('NG', 'Nigeria', 4),
('NL', 'Netherlands', 1),
('SG', 'Singapore', 3),
('UK', 'United Kingdom', 1),
('US', 'United States of America', 2),
('ZM', 'Zambia', 4),
('ZW', 'Zimbabwe', 4);

-- --------------------------------------------------------

--
-- Table structure for table `hr_department`
--

CREATE TABLE `hr_department` (
  `Department_Id` int(11) NOT NULL DEFAULT 0,
  `Department_Name` varchar(30) DEFAULT NULL,
  `Manager_Id` int(11) DEFAULT NULL,
  `Location_Id` int(11) DEFAULT NULL
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

--
-- Dumping data for table `hr_department`
--

INSERT INTO `hr_department` (`Department_Id`, `Department_Name`, `Manager_Id`, `Location_Id`) VALUES
(10, 'Administration', 200, 1700),
(20, 'Marketing', 201, 1800),
(30, 'Purchasing', 114, 1700),
(40, 'Human Resources', 203, 2400),
(50, 'Shipping', 121, 1500),
(60, 'IT', 103, 1400),
(70, 'Public Relations', 204, 2700),
(80, 'Sales', 145, 2500),
(90, 'Executive', 100, 1700),
(100, 'Finance', 100, 1700),
(110, 'Accounting', 205, 1700),
(120, 'Treasury', 0, 1700),
(130, 'Corporate Tax', 0, 1700),
(140, 'Control And Credit', 0, 1700),
(150, 'Shareholder Services', 0, 1700),
(160, 'Benifits', 0, 1700),
(170, 'Manufacturing', 0, 1700),
(180, 'Construction', 0, 1700),
(190, 'Contracting', 0, 1700),
(200, 'Operations', 0, 1700),
(210, 'IT Support', 0, 1700),
(220, 'NOC', 0, 1700),
(230, 'IT Helpdesk', 0, 1700),
(240, 'Government Sales', 0, 1700),
(250, 'Retail Sales', 0, 1700),
(260, 'Recruiting', 0, 1700),
(270, 'Payroll', 0, 1700);

-- --------------------------------------------------------

--
-- Table structure for table `hr_employees`
--

CREATE TABLE `hr_employees` (
  `Employee_Id` int(11) NOT NULL DEFAULT 0,
  `First_Name` varchar(20) DEFAULT NULL,
  `Last_Name` varchar(30) DEFAULT NULL,
  `Email` varchar(30) DEFAULT NULL,
  `Phone_Number` varchar(30) DEFAULT NULL,
  `Hire_Date` date DEFAULT NULL,
  `Job_id` varchar(20) DEFAULT NULL,
  `Salary` decimal(18,2) DEFAULT NULL,
  `Comission_PCT` decimal(18,2) DEFAULT NULL,
  `Manager_Id` int(11) DEFAULT NULL,
  `Department_Id` int(11) DEFAULT NULL
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

--
-- Dumping data for table `hr_employees`
--

INSERT INTO `hr_employees` (`Employee_Id`, `First_Name`, `Last_Name`, `Email`, `Phone_Number`, `Hire_Date`, `Job_id`, `Salary`, `Comission_PCT`, `Manager_Id`, `Department_Id`) VALUES
(100, 'Steven', 'King', 'SKING', '515.423.4567', '2003-06-17', 'AD-PRES', '24000.00', '0.00', 0, 90),
(101, 'Neena', 'Kochhar', 'NKOCHHER', '515.423.4568', '2005-09-21', 'AD_VP', '17000.00', '0.00', 100, 90),
(102, 'Lex', 'De Haan', 'LDEHAAN', '515.123.4569', '2001-01-13', 'AD_VP', '17000.00', '0.00', 100, 90),
(103, 'Alexander', 'Hunold', 'AHUNOLD', '590.423.4567', '2006-01-03', 'IT_PROG', '9000.00', '0.00', 102, 60),
(104, 'Bruce', 'Ernst', 'BERNST', '590.423.4568', '2007-05-21', 'IT_PROG', '6000.00', '0.00', 102, 60),
(105, 'David', 'Austin', 'DAUSTIN', '590.423.4569', '2005-06-25', 'IT_PROG', '4800.00', '0.00', 103, 60),
(106, 'Valli', 'Pataballa', 'VPATABAL', '590.423.4560', '2005-02-05', 'IT_PROG', '4800.00', '0.00', 103, 60),
(107, 'Diana', 'Lorentz', 'DLORENTZ', '590.423.5567', '2007-02-07', 'IT_PROG', '4200.00', '0.00', 103, 60),
(108, 'Nancy', 'Greenberg', 'NGREENBE', '515.124.4569', '2002-08-17', 'FI_MGR', '12008.00', '0.00', 101, 100),
(109, 'Daniel', 'Faviet', 'DFAVIET', '515.124.4169', '2002-08-16', 'FI_ACCOUNT', '9000.00', '0.00', 108, 100),
(110, 'John', 'Chen', 'JCHEN', '515.124.4269', '2002-09-28', 'FI_ACCOUNT', '8200.00', NULL, 108, 100),
(111, 'Ismael', 'Sciarra', 'ISCIARRA', '515.124.4369', '2005-09-30', 'FI_ACCOUNT', '7700.00', '0.00', 108, 100),
(112, 'Jose Manuel', 'Urman', 'JMURMAN', '515.124.4469', '2006-03-07', 'FI_ACCOUNT', '7800.00', '0.00', 108, 100),
(113, 'Luis', 'Popp', 'LPOPP', '515.124.4567', '2007-12-07', 'FI_ACCOUNT', '6900.00', '0.00', 108, 100),
(114, 'Den', 'Raphaely', 'DRAPHEAL', '515.127.4561', '2002-12-07', 'PU_MAN', '11000.00', '0.00', 100, 30),
(115, 'Alexander', 'Khoo', 'AKHOO', '515.127.4562', '2003-05-18', 'PU_CLERK', '3100.00', '0.00', 114, 30),
(116, 'Shelli', 'Baida', 'SBAIDA', '515.127.4563', '2005-12-24', 'PU_CLERK', '2900.00', '0.00', 114, 30),
(117, 'Sigal', 'Tobias', 'STOBIAS', '515.127.4564', '2005-07-24', 'PU_CLERK', '2800.00', '0.00', 114, 30),
(118, 'Guy', 'Himuro', 'GHIMURO', '515.127.4565', '2006-11-15', 'PU_CLERK', '2600.00', '0.00', 114, 30),
(119, 'Karen', 'Colmenares', 'KCOLMENA', '515.127.4566', '2006-08-10', 'PU_CLERK', '2500.00', '0.00', 114, 30),
(120, 'Mathew', 'Weiss', 'MWEISS', '650.123.1234', '2004-07-18', 'ST_MAN', '2500.00', '0.00', 100, 50),
(121, 'Adam', 'Fripp', 'AFRIPP', '650.123.2234', '2005-04-10', 'ST_MAN', '8200.00', '0.00', 100, 50),
(122, 'Payam', 'Kaufling', 'PKAUFLING', '650.123.3234', '2003-05-01', 'ST_MAN', '7900.00', '0.00', 100, 50),
(123, 'Shanta', 'Vollman', 'SVOLLMAN', '650.123.4234', '2005-10-10', 'ST_MAN', '6500.00', '0.00', 100, 50),
(124, 'Kevin', 'Morgous', 'KMORGOUS', '650.123.5234', '2007-11-16', 'ST_MAN', '5800.00', '0.00', 100, 50),
(125, 'Julia', 'Nayer', 'JNAYER', '650.124.1214', '2005-07-16', 'ST_CLERK', '3200.00', '0.00', 120, 50),
(126, 'Irene', 'Mikkilineni', 'IMIKKIL', '650.124.1224', '2006-09-28', 'ST_CLERK', '2700.00', '0.00', 120, 50),
(127, 'James', 'Landry', 'JLANDRY', '650.124.1334', '2007-01-14', 'ST_CLERK', '2400.00', '0.00', 120, 50),
(128, 'Steven', 'Markle', 'SMARKLE', '650.124.1434', '2008-03-08', 'ST_CLERK', '2200.00', '0.00', 120, 50),
(129, 'Laura', 'Bissot', 'LBISSOT', '650.124.5234', '2005-08-20', 'ST_CLERK', '3300.00', '0.00', 121, 50),
(130, 'Mozhe', 'Atkinson    ', 'MATKINSON', '650.124.6234', '2005-10-30', 'ST_CLERK', '2800.00', '0.00', 121, 50),
(131, 'James', 'Marlow', 'JMARLOW', '650.124.7234', '2005-02-16', 'ST_CLERK', '2500.00', '0.00', 121, 50),
(132, 'TJ', 'Olson', 'TJOLSON', '650.124.8234', '2007-04-10', 'ST_CLERK', '2100.00', '0.00', 121, 50),
(133, 'Jason', 'Mallin', 'JMALLIN', '650.127.1934', '2004-06-14', 'ST_CLERK', '3300.00', '0.00', 122, 50),
(134, 'Michael', 'Rogers', 'MROGERS', '650.127.1834', '2006-08-26', 'ST_CLERK', '2900.00', '0.00', 122, 50),
(135, 'Ki', 'Gee', 'KGEE', '650.127.1734', '2007-12-12', 'ST_CLERK', '2400.00', '0.00', 122, 50),
(136, 'Hazel', 'Philtanker', 'HPHILTAN', '650.127.1634', '2008-02-06', 'ST_CLERK', '2200.00', '0.00', 122, 50),
(137, 'Renske', 'Ladwig', 'RLADWIG', '650.121.1234', '2003-07-14', 'ST_CLERK', '3600.00', '0.00', 123, 50),
(138, 'Stephen', 'Stiles', 'SSTILES', '650.121.2034', '2005-10-26', 'ST_CLERK', '3200.00', '0.00', 123, 50),
(139, 'John', 'Seo', 'JSEO', '650.121.2019', '2006-02-12', 'ST_CLERK', '2700.00', '0.00', 123, 50),
(140, 'Joshua', 'Patel', 'JPATEL', '650.121.1834', '2006-04-06', 'ST_CLERK', '2500.00', '0.00', 123, 50),
(141, 'Trenna', 'Rajs', 'TRAJS', '650.121.8009', '2003-10-17', 'ST_CLERK', '3500.00', '0.00', 124, 50),
(142, 'Curtis', 'Davies', 'CDAVIES', '650.121.2994', '2005-01-29', 'ST_CLERK', '3100.00', '0.00', 124, 50),
(143, 'Randell', 'Matos', 'RMATOS', '650.121.2874', '2006-03-15', 'ST_CLERK', '2600.00', '0.00', 124, 50),
(144, 'Peter', 'Vargas', 'PVARGAS', '650.121.2004', '2006-07-09', 'ST_CLERK', '2500.00', '0.00', 124, 50),
(145, 'John', 'Russel', 'JRUSSEL', '011.44.1344.429268', '2004-10-01', 'SA_MAN', '14000.00', '0.40', 100, 80),
(146, 'Karen', 'Partners', 'KPARTNER', '011.44.1344.467268', '2005-01-05', 'SA_MAN', '13500.00', '0.30', 100, 80),
(147, 'Alberto', 'Errazuriz', 'AERRAZUR', '011.44.1344.429278', '2005-03-10', 'SA_MAN', '12000.00', '0.30', 100, 80),
(148, 'Gerald', 'Cambrault', 'GCAMBRAU', '011.44.1344.619268', '2007-10-15', 'SA_MAN', '11000.00', '0.30', 100, 80),
(149, 'Eleni', 'Zlotkey', 'EZLOTKEY', '011.44.1344.429018', '2008-01-29', 'SA_MAN', '10500.00', '0.20', 100, 80),
(150, 'Peter', 'Tucker', 'PTUCKER', '011.44.1344.129268', '2005-01-30', 'SA_REP', '10000.00', '0.30', 145, 80),
(151, 'David', 'Bernstein', 'DBERNSTE', '011.44.1344.345268', '2005-03-24', 'SA_REP', '9500.00', '0.25', 145, 80),
(152, 'Peter', 'Hall', 'PHALL', '011.44.1344.478968', '2005-08-20', 'SA_REP', '9000.00', '0.25', 145, 80),
(153, 'Christopher', 'Olsen', 'COLSEN', '011.44.1344.498718', '2006-03-30', 'SA_REP', '8000.00', '0.20', 145, 80),
(154, 'Nanette', 'Cambrault', 'NCAMBRAU', '011.44.1344.987668', '2006-12-09', 'SA_REP', '7500.00', '0.20', 145, 80),
(155, 'Oliver', 'Tuvault', 'OTUVAULT', '011.44.1344.486508', '2007-11-23', 'SA_REP', '7000.00', '0.15', 145, 80),
(156, 'Janette', 'King', 'JKING', '011.44.1345.429268', '2004-01-30', 'SA_REP', '10000.00', '0.35', 146, 80),
(157, 'Patrick', 'Sully', 'PSULLY', '011.44.1345.929268', '2004-03-04', 'SA_REP', '9500.00', '0.35', 146, 80),
(158, 'Allan', 'McEwen', 'AMCEWEN', '011.44.1345.829268', '2004-08-01', 'SA_REP', '9000.00', '0.35', 146, 80),
(159, 'Lindsay', 'Smith', 'LSMITH', '011.44.1345.729268', '2005-03-10', 'SA_REP', '8000.00', '0.30', 146, 80),
(160, 'Louisa', 'Doran', 'LDORAN', '011.44.1345.629268', '2005-12-15', 'SA_REP', '7500.00', '0.30', 146, 80),
(161, 'Sarath', 'Sewall', 'SSEWALL', '011.44.1345.529268', '2006-11-03', 'SA_REP', '7000.00', '0.25', 146, 80),
(162, 'Clara', 'Vishney', 'CVISHNEY', '011.44.1346.129268', '2005-11-11', 'SA_REP', '10500.00', '0.25', 147, 80),
(163, 'Danielle', 'Greene', 'DGREENE', '011.44.1346.229268', '2007-03-09', 'SA_REP', '9500.00', '0.15', 147, 80),
(164, 'Mattea', 'Marvins', 'MMARVINS', '011.44.1346.329268', '2008-01-24', 'SA_REP', '7200.00', '0.10', 147, 80),
(165, 'David', 'Lee', 'DLEE', '011.44.1346.529268', '2008-02-23', 'SA_REP', '6800.00', '0.10', 147, 80),
(166, 'Sundar', 'Ande', 'SANDE', '011.44.1346.629268', '2008-03-24', 'SA_REP', '6400.00', '0.10', 147, 80),
(167, 'Amit', 'Banda', 'ABANDA', '011.44.1346.729268', '2008-04-21', 'SA_REP', '6200.00', '0.10', 147, 80),
(168, 'Lisa', 'Ozer', 'LOZER', '011.44.1346.929268', '2005-03-11', 'SA_REP', '11500.00', '0.25', 148, 80),
(169, 'Harrison', 'Bloom', 'HBLOOM', '011.44.1343.829268', '2006-03-23', 'SA_REP', '10000.00', '0.20', 148, 80),
(170, 'Tayler', 'Fox', 'TFOX', '011.44.1343.729268', '2006-01-24', 'SA_REP', '9600.00', '0.20', 148, 80),
(171, 'William', 'Smith', 'WSMITH', '011.44.1343.629268', '2007-02-23', 'SA_REP', '7400.00', '0.15', 148, 80),
(172, 'Elizabeth', 'Bates', 'EBATES', '011.44.1343.529268', '2007-03-24', 'SA_REP', '7300.00', '0.15', 148, 80),
(173, 'Sundita', 'Kumar', 'SKUMAR', '011.44.1343.329268', '2008-04-21', 'SA_REP', '6100.00', '0.10', 148, 80),
(174, 'Ellen', 'Abel', 'EABEL', '011.44.1644.429267', '2004-05-11', 'SA_REP', '11000.00', '0.30', 149, 80),
(175, 'Alyssa', 'Hutton', 'AHUTTON', '011.44.1644.429266', '2005-03-19', 'SA_REP', '8800.00', '0.25', 149, 80),
(176, 'Jonathon', 'Taylor', 'JTAYLOR', '011.44.1644.429265', '2006-03-24', 'SA_REP', '8600.00', '0.20', 149, 80),
(177, 'Jack', 'Livingston', 'JLIVINGS', '011.44.1644.429264', '2006-04-23', 'SA_REP', '8400.00', '0.20', 149, 80),
(178, 'Kimberely', 'Grant', 'KGRANT', '011.44.1644.429263', '2007-05-24', 'SA_REP', '7000.00', '0.15', 149, 0),
(179, 'Charles', 'Johnson', 'CJOHNSON', '011.44.1644.429262', '2008-01-04', 'SA_REP', '6200.00', '0.10', 149, 80),
(180, 'Winston', 'Taylor', 'WTAYLOR', '650.507.9876', '2006-01-24', 'SH_CLERK', '3200.00', '0.00', 120, 50),
(181, 'Jean', 'Flear', 'JFLEAR', '650.507.9877', '2006-02-23', 'SH_CLERK', '3100.00', '0.00', 120, 50),
(182, 'Martha', 'Sullivan', 'MSULLIVA', '650.507.9878', '2007-06-21', 'SH_CLERK', '2500.00', '0.00', 120, 50),
(183, 'Girard', 'Geoni', 'GGEONI', '650.507.9879', '2008-02-03', 'SH_CLERK', '2800.00', '0.00', 120, 50),
(184, 'Nandita', 'Sarchand', 'NSARCHAN', '650.509.1876', '2004-01-27', 'SH_CLERK', '4200.00', '0.00', 121, 50),
(185, 'Alexis', 'Bull', 'ABULL', '650.509.2876', '2005-02-20', 'SH_CLERK', '4100.00', '0.00', 121, 50),
(186, 'Julia', 'Dellinger', 'JDELLING', '650.509.3876', '2006-06-24', 'SH_CLERK', '3400.00', '0.00', 121, 50),
(187, 'Anthony', 'Cabrio', 'ACABRIO', '650.509.4876', '2007-02-07', 'SH_CLERK', '3000.00', '0.00', 121, 50),
(188, 'Kelly', 'Chung', 'KCHUNG', '650.505.1876', '2005-06-14', 'SH_CLERK', '3800.00', '0.00', 122, 50),
(189, 'Jennifer', 'Dilly', 'JDILLY', '650.505.2876', '2005-08-13', 'SH_CLERK', '3600.00', '0.00', 122, 50),
(190, 'Timothy', 'Gates', 'TGATES', '650.505.3876', '2006-07-11', 'SH_CLERK', '2900.00', '0.00', 122, 50),
(191, 'Randall', 'Perkins', 'RPERKINS', '650.505.4876', '2007-12-19', 'SH_CLERK', '2500.00', '0.00', 122, 50),
(192, 'Sarah', 'Bell', 'SBELL', '650.501.1876', '2004-02-04', 'SH_CLERK', '4000.00', '0.00', 123, 50),
(193, 'Britney', 'Everett', 'BEVERETT', '650.501.2876', '2005-03-03', 'SH_CLERK', '3900.00', '0.00', 123, 50),
(194, 'Samuel', 'McCain', 'SMCCAIN', '650.501.3876', '2006-07-01', 'SH_CLERK', '3200.00', '0.00', 123, 50),
(195, 'Vance', 'Jones', 'VJONES', '650.501.4876', '2007-03-17', 'SH_CLERK', '2800.00', '0.00', 123, 50),
(196, 'Alana', 'Walsh', 'AWALSH', '650.507.9811', '2006-04-24', 'SH_CLERK', '3100.00', '0.00', 124, 50),
(197, 'Kevin', 'Fenny', 'KFENNY', '650.507.9822', '2006-05-23', 'SH_CLERK', '3000.00', '0.00', 124, 50),
(198, 'Donald', 'OConnell', 'DOCONNEL', '650.507.9833', '2007-06-21', 'SH_CLERK', '2600.00', '0.00', 124, 50),
(199, 'Douglas', 'Grant', 'DGRANT', '650.507.9844', '2008-01-13', 'SH_CLERK', '2600.00', '0.00', 124, 50),
(200, 'Jennifer', 'Whalen', 'JWHALEN', '515.123.4444', '2003-09-17', 'AD_ASST', '4400.00', '0.00', 101, 10),
(201, 'Michael', 'Hartstein', 'MHARTSTE', '515.123.5555', '2004-02-17', 'MK_MAN', '13000.00', '0.00', 100, 20),
(202, 'Pat', 'Fay', 'PFAY', '603.123.6666', '2005-08-17', 'MK_REP', '6000.00', '0.00', 201, 20),
(203, 'Susan', 'Mavris', 'SMAVRIS', '515.123.7777', '2002-06-07', 'HR_REP', '6500.00', '0.00', 101, 40),
(204, 'Hermann', 'Baer', 'HBAER', '515.123.8888', '2002-06-07', 'PR_REP', '10000.00', '0.00', 101, 70),
(205, 'Shelley', 'Higgins', 'SHIGGENS', '515.123.8080', '2002-06-07', 'AC_MGR', '12008.00', '0.00', 101, 110),
(206, 'William', 'Gietz', 'WGIETZ', '515.123.8181', '2002-06-07', 'AC_ACCOUNT', '8300.00', '0.00', 205, 110);

-- --------------------------------------------------------

--
-- Table structure for table `hr_jobs`
--

CREATE TABLE `hr_jobs` (
  `JOB_Id` varchar(20) NOT NULL,
  `Job_Title` varchar(50) DEFAULT NULL,
  `Min_Salary` int(11) DEFAULT NULL,
  `Max_Salary` int(11) DEFAULT NULL
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

--
-- Dumping data for table `hr_jobs`
--

INSERT INTO `hr_jobs` (`JOB_Id`, `Job_Title`, `Min_Salary`, `Max_Salary`) VALUES
('AD_PRES', 'President', 20080, 40000),
('AD_VP', 'Administration Vice President', 15000, 30000),
('AD_ASST', 'Administration Assistant', 3000, 6000),
('FI_MNGR', 'Finance Manager', 8200, 16000),
('FI_ACCOUNT', 'Accountant', 4200, 9000),
('AC_MGR', 'Accounting Manager', 8200, 16000),
('AC_ACCOUNT', 'Public Accountant', 4200, 9000),
('SA_MAN', 'Sales Manager', 10000, 20080),
('SA_REP', 'Sales Representative', 6000, 12008),
('PU_MAN', 'Purchasing Manager', 8000, 15000),
('PU_CLERK', 'Purchasing Clerk', 2500, 5500),
('ST_MAN', 'Stock Manager', 5500, 8500),
('ST_CLERK', 'Stock Clerk', 2008, 5000),
('SH_CLERK', 'Shipping Clerk', 2500, 5500),
('IT_PROG', 'Programmer', 4000, 10000),
('MK_MAN', 'Marketing Manager', 9000, 15000),
('MK_REP', 'Marketing Representative', 4000, 9000),
('HR_REP', 'Human Resource Representative', 4000, 9000),
('PR_REP', 'Public Relations Representative', 4500, 10500);

-- --------------------------------------------------------

--
-- Table structure for table `hr_job_history`
--

CREATE TABLE `hr_job_history` (
  `Employee_Id` int(11) NOT NULL DEFAULT 0,
  `Start_Date` date DEFAULT NULL,
  `End_Date` date DEFAULT NULL,
  `JOB_Id` varchar(20) DEFAULT NULL,
  `Department_Id` int(11) DEFAULT NULL
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

--
-- Dumping data for table `hr_job_history`
--

INSERT INTO `hr_job_history` (`Employee_Id`, `Start_Date`, `End_Date`, `JOB_Id`, `Department_Id`) VALUES
(102, '2001-01-13', '2006-04-27', 'IT_PROG', 60),
(101, '1997-09-21', '2001-10-27', 'AC_ACCOUNT', 110),
(201, '2004-02-17', '2007-12-19', 'MK_REP', 20),
(114, '2006-03-24', '2007-12-31', 'ST_CLERK', 50),
(122, '2007-01-01', '2007-12-31', 'ST_CLERK', 50),
(200, '1995-09-17', '2001-06-17', 'AD_ASST', 90),
(176, '2006-03-24', '2006-12-31', 'SA_REP', 80),
(200, '2002-07-01', '2006-12-31', 'AC_ACCOUNT', 90),
(176, '2007-01-01', '2007-12-31', 'SA_MAN', 80),
(101, '2001-10-28', '2005-03-15', 'AC_MGR', 110);

-- --------------------------------------------------------

--
-- Table structure for table `hr_locations`
--

CREATE TABLE `hr_locations` (
  `Location_Id` int(11) NOT NULL DEFAULT 0,
  `Street_Address` varchar(150) DEFAULT NULL,
  `postal_code` varchar(20) DEFAULT NULL,
  `City` varchar(50) DEFAULT NULL,
  `State_Province` varchar(50) DEFAULT NULL,
  `Country_Id` varchar(10) DEFAULT NULL
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

--
-- Dumping data for table `hr_locations`
--

INSERT INTO `hr_locations` (`Location_Id`, `Street_Address`, `postal_code`, `City`, `State_Province`, `Country_Id`) VALUES
(1000, '1297 Via Cola di Rie', '989', 'Roma', NULL, 'IT'),
(1100, '93091 Calle della Testa', '10934', 'Venice', NULL, 'IT'),
(1200, '2017 Shinjuku-ku', '1689', 'Tokyo', 'Tokyo Prefecture', 'JP'),
(1300, '9450 Kamiya-cho', '6823', 'Hiroshima', NULL, 'JP'),
(1400, '2014 Jabberwocky Rd', '26192', 'Southlake', 'Texas ', 'US'),
(1500, '2011 Interiors Blvd', '99236', 'South San Francisco', 'California', 'US'),
(1600, '2007 Zagora St', '50090', 'South Brunswick', 'New Jersey', 'US'),
(1700, '2004 Charade Rd', '98199', 'Seattle', 'Washington', 'US'),
(1800, '147 Spadina Ave', 'M5V 2L7', 'Toronto', 'Ontario', 'CA'),
(1900, '6092 Boxwood St', 'YSW 9T2', 'Whitehorse        ', 'Yukon', 'CA'),
(2000, '40-5-12 Laogiangge', '190518', 'Beijing        ', NULL, 'CN'),
(2100, '298 Vileparle (E)', '490231', 'Bombay', 'Maharashtra', 'IN'),
(2200, '12-98 Victoria Street', '2901', 'Sydney', 'New South Wales', 'AU'),
(2300, '198 Clementi North', '540198', 'Singapore', NULL, 'SG'),
(2400, '8204 Arthur St', NULL, 'London', NULL, 'UK'),
(2500, 'Magdalen Centre, The Oxford Science Park', 'OX9 9ZB', 'Oxford', NULL, 'UK'),
(2600, '9702 Chester Road', '9629850293', 'Stretford', 'Manchester', 'UK'),
(2700, 'Schwanthalerstr. 7031', '80925', 'Munich', 'Bavaria', 'DE'),
(2800, ' Rua Frei Caneca 1360 ', '01307-002', 'Sao Paulo', 'Sao Paulo', 'BR'),
(2900, '20 Rue des Corps-Saints', '1730', 'Geneva', 'Geneva', 'CH'),
(3000, ' Murtenstrasse 921', '3095', 'Bern', 'BE', 'CH'),
(3100, 'Pieter Breughelstraat 837', '3029SK', 'Utrecht', 'Utrecht', 'NL'),
(3200, 'Mariano Escobedo 9991', '11932', 'Mexico City', 'Distrito Federal', 'MX');

--
-- Indexes for dumped tables
--

--
-- Indexes for table `hr_department`
--
ALTER TABLE `hr_department`
  ADD PRIMARY KEY (`Department_Id`),
  ADD KEY `Location_Id` (`Location_Id`);

--
-- Indexes for table `hr_employees`
--
ALTER TABLE `hr_employees`
  ADD PRIMARY KEY (`Employee_Id`);

--
-- Indexes for table `hr_jobs`
--
ALTER TABLE `hr_jobs`
  ADD PRIMARY KEY (`JOB_Id`);

--
-- Indexes for table `hr_job_history`
--
ALTER TABLE `hr_job_history`
  ADD KEY `Employee_Id` (`Employee_Id`),
  ADD KEY `Department_Id` (`Department_Id`);

--
-- Indexes for table `hr_locations`
--
ALTER TABLE `hr_locations`
  ADD PRIMARY KEY (`Location_Id`);
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
