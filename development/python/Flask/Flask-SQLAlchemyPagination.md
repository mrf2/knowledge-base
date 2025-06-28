# Flask-SQLAlchemy Pagination Example
---
title:Flask-SQLAlchemy Pagination
dependences: [Flask, Flask-SQLAlchemy]
categoy: Flask
update: 28 Jun 2025
---
1. Set up development environment
```bash
python3 -m venv pythonvenv
source pythonvenv/bin/activate
```
2. Install dependencies
```bash
pip install Flask Flask-SQLAlchemy
```
3. Create [Flask App](app.py)
4. Create the [HTML template](items.html)
```vim
1. Create a directory named "templates" in the same directory as "app.py"
2. Inside "templates", crate a file named "items.html"
```
5. Initialize the database and add [sample data](sammple_data.md)
6. Run the Flask app
```bash
1. python app.py
2. Open a browser and go to: http://127.0.0.1:5000/items
```
