const db = require('../database');
const bcrypt = require('bcryptjs');

const saltRounds=10;
const kortti={
  get: function(callback) {
    return db.query('select * from kortti', callback);
  },
  getById: function(id, callback) {
    return db.query('select * from kortti where idKortti=?', [id], callback);
  },
  add: function(kortti, callback) {
    bcrypt.hash(kortti.pin, saltRounds, function(err, hash) {
      return db.query('insert into kortti (idKortti, pin, idAsiakas) values (?,?,?)',
      [kortti.idKortti, hash, kortti.idAsiakas], callback);
    });
  },
  delete: function(id, callback) {
    return db.query('delete from kortti where idKortti=?', [id], callback);
  },
  update: function(id, kortti, callback) {
    bcrypt.hash(kortti.pin, saltRounds, function(err, hash) {
      return db.query('update kortti set pin=? where idKortti=?',
      [hash, id], callback);
    });
  }

}

module.exports = kortti;