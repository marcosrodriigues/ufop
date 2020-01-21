import { async, ComponentFixture, TestBed } from '@angular/core/testing';

import { DescricaoPersonalidadeComponent } from './descricao-personalidade.component';

describe('DescricaoPersonalidadeComponent', () => {
  let component: DescricaoPersonalidadeComponent;
  let fixture: ComponentFixture<DescricaoPersonalidadeComponent>;

  beforeEach(async(() => {
    TestBed.configureTestingModule({
      declarations: [ DescricaoPersonalidadeComponent ]
    })
    .compileComponents();
  }));

  beforeEach(() => {
    fixture = TestBed.createComponent(DescricaoPersonalidadeComponent);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});
