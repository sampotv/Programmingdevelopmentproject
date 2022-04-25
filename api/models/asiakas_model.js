const db = require('../database');
const bcrypt = require('bcryptjs');

const saltRounds = 10;
const asiakas={
    get: function(callback) {
        return db.query('select * from asiakas', callback);
    },
    getById: function(id, callback) {
        return db.query('select * from asiakas where idAsiakas=?', [id], callback);
    },
    add: function(asiakas, callback) {
        return db.query('insert into asiakas (enimi, snimi, osoite, puhnro) values (?,?,?,?)', [asiakas.enimi, asiakas.snimi, asiakas.osoite, asiakas.puhnro], callback);
    },
    delete: function(id, callback) {
        return db.query('delete from asiakas where idAsiakas=?', [id], callback);
    },
    update: function(id, asiakas, callback) {
        return db.query('update asiakas set enimi=?, snimi=?, osoite=?, puhnro=? where idAsiakas=?', [asiakas.enimi, asiakas.snimi, asiakas.osoite, asiakas.puhnro, id], callback);
    }
}
module.exports = asiakas;