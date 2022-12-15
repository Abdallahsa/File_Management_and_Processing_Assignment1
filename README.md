# File_Management_and_Processing_Assignment1
We want to store data about Employees and Department. (for simplicity consider any employee belongs to only one department, but any department may have more than one employee)
We want to store data about Employees and Department. (for simplicity consider any employee belongs to only one department, but
any department may have more than one employee)
Consider we want to save 10 Employees and 5 Department.
Save the data for employees and department in the following format: delimited fields, length indicator records.
You should write the producers that build the following indexes:
1. Primary index using the Employee_ID (for Employees datafile)
2. Primary index using the Dept_ID (for Department datafile)
3. Secondary index using Dept_ID (for Employee datafile) //Dept _ID is sec. key in Employees datafile
4. Secondary index using Dept_Name (for Department datafile)
The user can write a query that contains fixed key words (formatted in red below)
Examples for queries that user can write
▪ select all from Employee where Dept_ID = ’xxxx’ // this query will use sec. index to get results
▪ select all from Department where Dept_ID = ’xxxx’ // this query will use primary. index to get results
▪ select Employee_Name from Employee where Employee_ID = ’xxxx’ // this query will use sec. index to get results
The main welcome screen is below.
Important notes:
All indexes are sorted ascending
You MUST implement secondary indexes using Linked List technique.
Searching in indexes is performed using binary search.
To delete a record just put an * in the beginning of that record. (no need for avail list implementation)
All operations (add, delete) will affect indexes.
Search operations will use indexes (primary or secondary)
Bind all secondary indexes with the primary index, don’t bind them by addresses directly
