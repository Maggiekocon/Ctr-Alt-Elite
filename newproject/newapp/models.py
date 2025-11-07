from django.db import models

class Question(models.Model):
    question_text = models.CharField(max_length=255)

    # Four possible answers
    answer1 = models.CharField(max_length=255)
    answer2 = models.CharField(max_length=255)
    answer3 = models.CharField(max_length=255)
    answer4 = models.CharField(max_length=255)

    # Store which answer is correct (1–4)
    CORRECT_CHOICES = [
        (1, 'Answer 1'),
        (2, 'Answer 2'),
        (3, 'Answer 3'),
        (4, 'Answer 4'),
    ]
    correct_answer = models.IntegerField(choices=CORRECT_CHOICES)

    def __str__(self):
        return self.question_text



