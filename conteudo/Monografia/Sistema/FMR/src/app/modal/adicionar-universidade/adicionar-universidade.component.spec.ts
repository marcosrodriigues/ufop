import { async, ComponentFixture, TestBed } from '@angular/core/testing';

import { AdicionarUniversidadeComponent } from './adicionar-universidade.component';

describe('AdicionarUniversidadeComponent', () => {
  let component: AdicionarUniversidadeComponent;
  let fixture: ComponentFixture<AdicionarUniversidadeComponent>;

  beforeEach(async(() => {
    TestBed.configureTestingModule({
      declarations: [ AdicionarUniversidadeComponent ]
    })
    .compileComponents();
  }));

  beforeEach(() => {
    fixture = TestBed.createComponent(AdicionarUniversidadeComponent);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});
