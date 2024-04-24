let playerText = document.getElementById('playerText');
let restartBtn = document.getElementById('restartBtn');
let findBtn = document.getElementById('find');
let nameInput = document.getElementById('name');
let oppNameSpan = document.getElementById('oppName');

let userWinsSpan = document.getElementById('userWins');
let drawsSpan = document.getElementById('drawsCount')
let oppWinsSpan = document.getElementById('oppWins');

let enterNameDiv = document.getElementById('enterName');
let userCont = document.getElementById('userCont');
let oppNameCont = document.getElementById('oppNameCont');
let userSpan = document.getElementById('user');
let gameboardDiv = document.getElementById('gameboard');
let boxes = Array.from(document.getElementsByClassName('box'));

const winnerIndicator = getComputedStyle(document.body).getPropertyValue('--winning-blocks');

const O_TEXT = "o";
const X_TEXT = "x";

let userWins = 0;
let draws = 0;
let oppWins = 0;

let currentPlayer = X_TEXT; // x starts
let currentPlayerName = nameInput;
let spaces = Array(9).fill(null); // all spaces free
let playerName = '';
let isPlayerTurn = true; // Boolean flag to track the current player's turn

findBtn.addEventListener('click', startGame);

// Connect to the server using socket.io
let socket = io();

function startGame() {
    playerName = nameInput.value.trim();

    if (playerName === '') {
        alert('Please enter your name before starting the game.');
        return;
    }

    enterNameDiv.style.display = 'none';
    userCont.style.display = 'block';
    oppNameCont.style.display = 'block';
    gameboardDiv.style.display = 'flex';
    restartBtn.style.display = 'inline-block';

    // Set the user's name
    userSpan.textContent = playerName;

    // Notify the server that the player has joined
    socket.emit('joinGame', playerName);

    // Unchanged - Event listeners for box clicks
    boxes.forEach(box => box.addEventListener('click', boxClicked));
    updatePlayerText();
}
function boxClicked(e) {
    if (!isPlayerTurn) {
        // If it's not the player's turn, return early
        playerText.innerHTML = `Not your turn :(`;
        return;
    }

    const id = e.target.id;

    if (!spaces[id]) {
        spaces[id] = currentPlayer;
        e.target.innerText = currentPlayer;

        // Notify the server that a box has been clicked
        socket.emit('boxClicked', { id, currentPlayer });

        // Unchanged - Check for game outcomes
        const gameResult = playerHasWon();
        if (gameResult) {
            playerText.innerHTML = `${currentPlayer} has won!`;

            if (currentPlayerName === nameInput) {
                userWins++;
            } else {
                oppWins++;
            }
            userWinsSpan.textContent = userWins;
            oppWinsSpan.textContent = oppWins;

            let winning_blocks = gameResult;
            winning_blocks.map((box) => (boxes[box].style.backgroundColor = winnerIndicator));
            disableClicks();
            return;
        } else if (spaces.every((space) => space !== null)) {
            draws++;
            playerText.innerHTML = 'It\'s a draw!';

            // Update the playerInfo on the HTML page
            drawsSpan.textContent = draws;
            disableClicks();
            return;
        }

        isPlayerTurn = false; // Switch turn after the move
        playerText.innerHTML = `Your turn :)`;
        updatePlayerText();
    }
}


// Unchanged - Winning combinations and check function
const winningCombos = [
    [0, 1, 2],
    [3, 4, 5],
    [6, 7, 8],
    [0, 3, 6],
    [1, 4, 7],
    [2, 5, 8],
    [0, 4, 8],
    [2, 4, 6]
];

function playerHasWon() {
    for (const condition of winningCombos) {
        let [a, b, c] = condition;

        if (spaces[a] && (spaces[a] === spaces[b] && spaces[a] === spaces[c])) {
            return [a, b, c];
        }
    }
    return false;
}

// Changed - Restart button click event
restartBtn.addEventListener('click', () => {
    restart();

    // Notify the server that the game should be restarted
    socket.emit('restart');
});

// Unchanged - Restart game function
function restart() {
    spaces.fill(null);

    boxes.forEach(box => {
        box.innerText = '';
        box.style.backgroundColor = '';
    });

    playerText.innerHTML = 'Tic Tac Toe';
    currentPlayer = X_TEXT;
    enableClicks();
    updatePlayerText();
};


// Changed - Event listeners for socket events
socket.on('playerJoined', (opponentName) => {
    oppNameSpan.textContent = opponentName;
});

socket.on('boxClicked', (data) => {
    const { id, currentPlayer } = data;
    spaces[id] = currentPlayer;
    document.getElementById(id).innerText = currentPlayer;

    // Unchanged - Check for game outcomes
    if (playerHasWon() !== false) {
        playerText.innerHTML = `${currentPlayer} has won!`;
        let winning_blocks = playerHasWon();

        winning_blocks.map(box => boxes[box].style.backgroundColor = winnerIndicator);
        disableClicks();
        return;
    } else if (spaces.every(space => space !== null)) {
        playerText.innerHTML = 'It\'s a draw!';
        disableClicks();
        return;
    }

    isPlayerTurn = true; // Switch turn after the move
    updatePlayerText();
});


socket.on('restart', () => {
    restart();
});

// Unchanged - Additional functions
function updatePlayerText() {
    currentPlayer = (currentPlayer === X_TEXT) ? O_TEXT : X_TEXT;
    if (isPlayerTurn) {
        playerText.innerHTML = `Your turn :)`;
    } else {
        playerText.innerHTML = '';
    }
}

function disableClicks() {
    boxes.forEach(box => box.removeEventListener('click', boxClicked));
}

function enableClicks() {
    boxes.forEach(box => box.addEventListener('click', boxClicked));
}

// Unchanged - Initial game start
startGame();
