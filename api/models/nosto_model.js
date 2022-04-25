const db = require('../database');

const nosto = {
    debit: function(postData, callback){
        return db.query('call nosto(?,?)',[postData.id1, postData.summa], callback);

    },
    credit: function(postData, callback){
        return db.query('call credit_nosto(?,?)',[postData.id, postData.summa], callback);

    }
};

module.exports = nosto;