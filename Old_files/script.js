function prepareQuizData() {
    window.difficultyList = ["Easy", "Medium", "Hard", "Extreme"];
    window.categoryList = ["Wissenschaft", "Kultur", "Zeitgeschehen", "Religion", "Allgemein", "Erdkunde"];
    window.quizData = [
        {
            "category": 0,
            "difficulty": 1,
            "question": "Was bedeutet die Bezeichnung LHC?",
            "answer": "Large Hadron Collider",
            "options": [
                "Light Helium Construction",
                "Left Height Certainty",
                "Linear Helix Correction"
            ]
        }, {
            "category": 1,
            "difficulty": 0,
            "question": "Wer sang das Lied 'Currywurst'?",
            "answer": "Herberg Grönemeyer",
            "options": [
                "Helge Schneider",
                "Dieter Nuhr",
                "Wiegald Boning"
            ]
        }
    ];
}

function createQuizOverview() {
    // Create table
    let overview = document.getElementById('overview');
    let tbl = document.createElement('table');
    tbl.classList.add('table');
    // Create table header
    let tHead = tbl.createTHead()
    let thRow = tHead.insertRow();
    window.categoryList.forEach(catStr => {
        let th = document.createElement("th");
        th.scope = 'col';
        let text = document.createTextNode(catStr);
        th.appendChild(text);
        thRow.appendChild(th);
    });
    // Create table body
    let tBody = tbl.createTBody();
    window.difficultyList.forEach(diffStr => {
        let tbRow = tBody.insertRow();
        window.categoryList.forEach(catStr => {
            let td = document.createElement('td');
            td.scope = 'col';
            let text = document.createTextNode(`${catStr} - ${diffStr}`);
            td.appendChild(text);
            tbRow.appendChild(td);
        });
    });
    overview.appendChild(tbl);   
}
window.onload = () => {
    prepareQuizData();
    createQuizOverview();
}