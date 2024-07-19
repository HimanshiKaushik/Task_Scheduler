document.getElementById('taskForm').addEventListener('submit', function(e) {
    e.preventDefault();
    const taskName = document.getElementById('taskName').value.trim();
    const taskPriority = parseInt(document.getElementById('taskPriority').value.trim(), 10);

    console.log("Task Name: ", taskName);
    console.log("Task Priority: ", taskPriority);

    if (taskName && !isNaN(taskPriority)) {
        addTask(taskName, taskPriority);
        document.getElementById('taskForm').reset();
    } else {
        alert('Please enter a valid task name and priority.');
    }
});

function addTask(name, priority) {
    const taskList = document.getElementById('taskList');
    const li = document.createElement('li');
    li.innerHTML = `<span>${name}</span><span>Priority: ${priority}</span>`;
    taskList.appendChild(li);
    console.log("Task added: ", name, priority);
}