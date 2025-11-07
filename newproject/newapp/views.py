from django.shortcuts import render
from .models import Question

def quiz_view(request):
    # Get all questions from the database
    questions = Question.objects.all()
    return render(request, 'index.html', {'questions': questions})

