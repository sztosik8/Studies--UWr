const http = require('http');
const fs = require('fs');
const path = require('path');
const socketIo = require('socket.io');

const server = http.createServer((req, res) => {
    let filePath = '.' + req.url;
    if (filePath === './') {
        filePath = './index.html';
    }

    const extname = String(path.extname(filePath)).toLowerCase();
    const contentType = {
        '.html': 'text/html',
        '.css': 'text/css',
        '.js': 'application/javascript',
    }[extname] || 'application/octet-stream';

    fs.readFile(filePath, (err, content) => {
        if (err) {
            if (err.code === 'ENOENT') {
                res.writeHead(404, { 'Content-Type': 'text/plain' });
                res.end('File not found');
            } else {
                res.writeHead(500, { 'Content-Type': 'text/plain' });
                res.end('Internal Server Error');
            }
        } else {
            res.writeHead(200, { 'Content-Type': contentType });
            res.end(content, 'utf-8');
        }
    });
});

const io = socketIo(server);

const players = {}; // To store player information

io.on('connection', (socket) => {
    console.log('A user connected');

    socket.on('joinGame', (playerName) => {
        if (Object.keys(players).length < 2) {
            // Assign a unique identifier to the player
            const playerId = socket.id;

            // Store player information
            players[playerId] = {
                playerName,
                socket,
            };

            // Notify the current player about their opponent
            const opponentId = Object.keys(players).find(id => id !== playerId);
            if (opponentId) {
                socket.emit('playerJoined', players[opponentId].playerName);
                players[opponentId].socket.emit('playerJoined', playerName);
            }

            // Broadcast to all clients that a new player has joined
            io.emit('updatePlayerList', Object.values(players).map(player => player.playerName));
        } else {
            socket.emit('gameFull');
        }
    });

    socket.on('boxClicked', (data) => {
        const { id, currentPlayer } = data;
        const playerId = socket.id;

        // Find the opponent ID
        const opponentId = Object.keys(players).find(id => id !== playerId);

        // Check if the opponent exists before emitting the event
        if (players[opponentId] && players[opponentId].socket) {
            players[opponentId].socket.emit('boxClicked', data);
        }


    });

    socket.on('restartGame', () => {
        // Broadcast to all clients that the game should be restarted
        io.emit('restartGame');
    });

    socket.on('disconnect', () => {
        const playerId = socket.id;
        delete players[playerId];

        // Notify the remaining player that their opponent has disconnected
        const remainingPlayerId = Object.keys(players)[0];
        if (remainingPlayerId && players[remainingPlayerId].socket) {
            players[remainingPlayerId].socket.emit('opponentDisconnected');
        }

        io.emit('updatePlayerList', Object.values(players).map(player => player.playerName));
        console.log('User disconnected');
    });
});

const PORT = 8080;

server.listen(PORT, () => {
    console.log(`Server running at http://localhost:${PORT}/`);
});