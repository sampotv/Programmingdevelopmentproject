const db = require('../database');


const saldo = {

    saldo: function(postData, callback){
        return db.query('call saldo(?)',[postData.id], callback);

    }
};

    module.exports = saldo;