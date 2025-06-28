# Paginator
A **paginator** is a `tool`, `component`, or `technique` used to split a large set of data (like a long list of items or search results) into **smaller chunks of pages**, It allows users to *navigate* through these chunks instead of loading everything at once.

---
## Paginator uses:
 * **Websites:** At the bottom of blogs or e-commerce sites:  $\ll$ `Previous 1 2 3 ... Next` $\gg$
 * **APIs:** RESTful APIs often return results with pagination metadata (e.g., `page`, `per_page`, `next_url`).
 * **Command-line tools:** `less`, `more`, or `man` act like paginators.
 * **Programming frameworks:** ***Django, Flask, Laravel***, etc., have built-in pagination utilities.
 * **Improves performance:** Paginator imporves performance by loading a subset of data.
 * **Enhances user experience** by organizing content.
 * **Saves bandwidth** and processing time.
---
# Example in Django:
```python
from django.core.paginator import Paginator

objects = definedModel.objects.all()
paginator = Paginator(objects. 10)  # 10 items per page
page_obj = paginator.get_page(1)    # Get the first page
