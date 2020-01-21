import { TestBed } from '@angular/core/testing';

import { RepublicaService } from './republica.service';

describe('RepublicaService', () => {
  beforeEach(() => TestBed.configureTestingModule({}));

  it('should be created', () => {
    const service: RepublicaService = TestBed.get(RepublicaService);
    expect(service).toBeTruthy();
  });
});
