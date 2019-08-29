import { TestBed } from '@angular/core/testing';

import { InventarioService } from './inventario.service';

describe('InventarioService', () => {
  beforeEach(() => TestBed.configureTestingModule({}));

  it('should be created', () => {
    const service: InventarioService = TestBed.get(InventarioService);
    expect(service).toBeTruthy();
  });
});
