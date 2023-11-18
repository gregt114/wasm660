const express = require('express');
const WASM = require('./node.js');

const app = express();
const port = 3000;

app.use(express.json());

// Setup WASM
let process;
WASM().then(m => {
    process = m.cwrap("process", "string", ["string", "int"]);
});

// Define a route to handle POST requests
app.post('/post-data', (req, res) => {
  const message = req.body.message;
  const length = req.body.length;
  let result = process(message, length);

  res.json({ response: result });
});

// Start the server
app.listen(port, () => {
  console.log(`Server is running on http://localhost:${port}`);
});
