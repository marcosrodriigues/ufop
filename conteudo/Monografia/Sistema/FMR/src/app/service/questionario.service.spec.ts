import { TestBed } from '@angular/core/testing';

import { QuestionarioService } from './questionario.service';

describe('QuestionarioService', () => {
  beforeEach(() => TestBed.configureTestingModule({}));

  it('should be created', () => {
    const service: QuestionarioService = TestBed.get(QuestionarioService);
    expect(service).toBeTruthy();
  });
});
