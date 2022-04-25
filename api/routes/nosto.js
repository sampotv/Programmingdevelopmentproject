const express = require('express');
const router = express.Router();
const nosto = require('../models/nosto_model');

router.post('/nosto', function(request, response){
    nosto.debit(request.body, function(err, dbResult){
        if(err){
            response.json(err);
        }
        else{
            response.json(dbResult.affectedRows);
        }
    })

}
);

router.post('/credit_nosto', function(request, response){
    nosto.credit(request.body, function(err, dbResult){
        if(err){
            response.json(err);
        }
        else{
            response.json(dbResult.affectedRows);
        }
    })

}
);

module.exports = router;