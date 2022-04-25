const express = require('express');
const router = express.Router();
const tili = require('../models/tili_model');

router.get('/:id?',
function(request, response) {
    if (request.params.id) {
        tili.getById(request.params.id, function(err, dbResult) {
            if (err) {
                response.json(err);
            } else {
                response.json(dbResult);
            }
        });
    } else {
        tili.get(function(err, dbResult) {
            if (err) {
                response.json(err);
            } else {
                response.json(dbResult);
            }
        });
    }
});
module.exports = router;