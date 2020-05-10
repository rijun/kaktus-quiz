class QuizCategory:
    def __init__(self, name):
        self.name = name
        self.questions = {
            'easy': [],
            'medium': [],
            'hard': [],
            'extreme': []
        }
