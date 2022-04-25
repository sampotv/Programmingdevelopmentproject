const db = require('../database');
const bcrypt = require('bcryptjs');

const saltRounds = 10;
const tili={
    get: function(callback) {
        return db.query('select * from tili', callback);
    },
    getById: function(id, callback) {
        return db.query('select * from tili where idTili=?', [id], callback);
    },
    add: function(tili, callback) {
        return db.query('insert into tili (saldo, credit, luottoraja, idKortti) values (?,?,?,?)', [tili.saldo, tili.credit, tili.luottoraja, tili.idKortti], callback);
    },
    delete: function(id, callback) {
        return db.query('delete from tili where idTili=?', [id], callback);
    },
    update: function(id, tili, callback) {
        return db.query('update tili set saldo=?, credit=?, luottoraja=?, idKortti=? where idTili=?', [tili.saldo, tili.credit, tili.luottoraja, tili.idKortti, id], callback);
    }
}
module.exports = tili;