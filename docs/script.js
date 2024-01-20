document.addEventListener('DOMContentLoaded', function () {
    // Sample blog posts data
    const postsData = [
        { title: 'First Post', content: 'This is the content of the first post.' },
        { title: 'Second Post', content: 'Another post with some content.' },
        // Add more posts as needed
    ];

    const postsContainer = document.getElementById('posts');

    // Loop through posts data and create HTML elements
    postsData.forEach(post => {
        const postElement = document.createElement('div');
        postElement.classList.add('post');

        const titleElement = document.createElement('h2');
        titleElement.textContent = post.title;

        const contentElement = document.createElement('p');
        contentElement.textContent = post.content;

        postElement.appendChild(titleElement);
        postElement.appendChild(contentElement);

        postsContainer.appendChild(postElement);
    });
});
