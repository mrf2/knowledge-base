from flask import Flask, request, render_template
from flask_sqlalchemy import SQLAlchemy

app = Flask(__name__)
app.config['SQLALCHEMY_DATABASE_URI'] = 'sqlite:///exampl.db' # Database connection to a SQLite database file named "exmple.db" located in the same directory as "app.py"
db = SQLAlchemy(app)

class Item(db.Model):
    id = db.Column(db.Integer, primary_key=True)
    name = db.Column(db.String(100))

@app.route('/items')
def list_items():
    # Get the 'page' query parameter, default to 1
    page = request.args.get('page', 1, type=int)
    per_page = 10 # items per page

    pagination = Item.query.paginate(page=page, per_page=per_page)

    return render_template('items.html', items=pagination.items, page = page, total_pages = pagination.pages)

if __name__ == '__main__':
    app.run(debug=True)

