const mysql = require('mysql');

const myConnectionString = "mysql://atmuser:atmpass@localhost:3306/bank";

const connection = mysql.createConnection(myConnectionString);

module.exports = connection;