import { TestBed } from '@angular/core/testing';

import { UniversidadeService } from './universidade.service';

describe('UniversidadeService', () => {
  beforeEach(() => TestBed.configureTestingModule({}));

  it('should be created', () => {
    const service: UniversidadeService = TestBed.get(UniversidadeService);
    expect(service).toBeTruthy();
  });
});
