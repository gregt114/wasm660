const express = require('express');
const WASM = require("./format.js");

const app = express();
const port = 3000;

app.use(express.json());

let vuln;
WASM().then(m => {
    vuln = m.cwrap("vuln", "string", ["string"]);
})

app.post('/api', (req, res) => {
    let data = req.body.msg;

    let resp = vuln(data);

    res.json({response: resp});
});

// Start the server
app.listen(port, () => {
  console.log(`Server is running at http://localhost:${port}`);
});
