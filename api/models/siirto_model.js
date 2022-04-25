const db = require('../database');
//luodaan siirto-niminen objekti
//ja sen sisään tarvittavat funktiot
const siirto = {

    debit: function(postData, callback){
        return db.query('call debit_transfer(?,?,?)',
        [postData.id1, postData.id2, postData.summa],
        callback);
    },
    credit: function(postData, callback){
        return db.query('call credit_transfer(?,?,?)',
        [postData.id1, postData.id2, postData.summa],
        callback);
    }
};
//exportilla viedään ulos siirto objekti
module.exports = siirto;