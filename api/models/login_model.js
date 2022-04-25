const db = require('../database');

const login={
  checkPassword: function(idKortti, callback) {
      return db.query('SELECT pin, idTili FROM kortti inner join tili on kortti.idKortti=tili.idKortti WHERE kortti.idKortti = ?',[idKortti], callback); 
    }
};
          
module.exports = login;