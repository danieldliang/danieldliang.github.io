// Toggle the mobile navigation menu.
const navBtn = document.getElementById('navBtn');
const navList = document.getElementById('mainMenu');

if (navBtn) {
  navBtn.addEventListener('click', () => {
    const isOpen = navList.classList.toggle('open');
    navBtn.setAttribute('aria-expanded', isOpen);
  });
}

// Handle the contact form. Replace the timeout with a real request.
const form = document.getElementById('contactForm');
const formMsg = document.getElementById('formMsg');

if (form) {
  form.addEventListener('submit', async (e) => {
    e.preventDefault();
    formMsg.textContent = 'Sending…';

    // Simulate a network request.
    await new Promise(r => setTimeout(r, 800));

    form.reset();
    formMsg.textContent = 'Thank you! We’ll get back to you soon.';
  });
}

// Insert the current year in the footer.
document.getElementById('year').textContent = new Date().getFullYear();

// Fade-in elements as they scroll into view.
const animatedEls = document.querySelectorAll('[data-animate]');
const observer = new IntersectionObserver((entries) => {
  entries.forEach(entry => {
    if (entry.isIntersecting) entry.target.classList.add('in-view');
  });
}, { threshold: 0.15 });

animatedEls.forEach(el => observer.observe(el));
