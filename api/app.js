var express = require('express');
var path = require('path');
var cookieParser = require('cookie-parser');
var logger = require('morgan');
const helmet = require('helmet');
const cors = require('cors');

var indexRouter = require('./routes/index');
var usersRouter = require('./routes/users');
var asiakasRouter = require('./routes/asiakas');
var tiliRouter = require('./routes/tili');
var korttiRouter = require('./routes/kortti');
var loginRouter = require('./routes/login');
var siirtoRouter = require('./routes/siirto');
//var saldoRouter = require('./routes/saldo');
var tilitapahtumatRouter = require('./routes/tilitapahtumat');
var nostoRouter = require('./routes/nosto');

var app = express();


app.use(logger('dev'));
app.use(express.json());
app.use(express.urlencoded({ extended: false }));
app.use(cookieParser());
app.use(express.static(path.join(__dirname, 'public')));

app.use('/', indexRouter);
app.use('/users', usersRouter);
app.use('/asiakas', asiakasRouter);
app.use('/tili', tiliRouter);
app.use('/kortti', korttiRouter);
app.use('/login', loginRouter);
app.use('/siirto', siirtoRouter);
//app.use('/saldo', saldoRouter);
app.use('/tilitapahtumat', tilitapahtumatRouter);
app.use('/nosto', nostoRouter);
module.exports = app;
