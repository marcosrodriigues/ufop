import { TestBed } from '@angular/core/testing';

import { PersonalidadeService } from './personalidade.service';

describe('PersonalidadeService', () => {
  beforeEach(() => TestBed.configureTestingModule({}));

  it('should be created', () => {
    const service: PersonalidadeService = TestBed.get(PersonalidadeService);
    expect(service).toBeTruthy();
  });
});
