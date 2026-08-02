SELECT unique_id, name
FROM Employees as e
LEFT JOIN EmployeeUNI as eu
    ON  e.id = eu.id;