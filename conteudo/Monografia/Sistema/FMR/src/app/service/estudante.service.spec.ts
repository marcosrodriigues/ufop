import { TestBed } from '@angular/core/testing';

import { EstudanteService } from './estudante.service';

describe('EstudanteService', () => {
  beforeEach(() => TestBed.configureTestingModule({}));

  it('should be created', () => {
    const service: EstudanteService = TestBed.get(EstudanteService);
    expect(service).toBeTruthy();
  });
});
