const db = require('../database');
//luodaan siirto-niminen objekti
//ja sen sisään tarvittavat funktiot
const tilitapahtumat = {
    get: function(callback) {
        return db.query('select summa, tapahtuma, date_format(pvm,"%d.%m.%Y : %H.%i.%s") as pvm from tilitapahtumat', callback);
    },
    getById: function(id, callback) {
        return db.query('select summa, tapahtuma, date_format(pvm,"%d.%m.%Y : %H.%i.%s") as pvm from tilitapahtumat where idTili=? order by pvm desc limit 10', [id], callback);
        //return db.query('call tapahtuma(?)',[id],callback)
    }
};
//exportilla viedään ulos siirto objekti
module.exports = tilitapahtumat;